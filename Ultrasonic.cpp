// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// GitHub: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04
// #### LICENSE ####
// This code is licensed under Creative Commons Share alike
// and Attribution by J.Rodrigo ( http://www.jrodrigo.net ).

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int TP, int EP) :
    trigPin(TP), echoPin(EP), timeOut(23310)
{}

Ultrasonic::Ultrasonic(int TP, int EP, long TO) :
    trigPin(TP), echoPin(EP), timeOut(TO)
{}

void Ultrasonic::Config() {
  pinMode(this->trigPin, OUTPUT);
  pinMode(this->echoPin, INPUT);
}

void Ultrasonic::Timing() {
  digitalWrite(this->trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(this->trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trigPin, LOW);

  this->duration = pulseIn(this->echoPin, HIGH, this->timeOut);

  if (duration == 0)
    this->duration = this->timeOut;
  
  return;
}

long Ultrasonic::Ranging(int sys) {
  Timing();
  return sys ? this->duration / 58 : // cm
               this->duration / 147; // in
}
