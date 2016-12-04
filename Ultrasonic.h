// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// GitHub: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04
// #### LICENSE ####
// This code is licensed under Creative Commons Share alike
// and Attribution by J.Rodrigo ( http://www.jrodrigo.net ).

#ifndef Ultrasonic_h
#define Ultrasonic_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define CM  1
#define INC 0

class Ultrasonic {
  public:
    //Constructors.
    Ultrasonic(int TP, int EP);
    Ultrasonic(int TP, int EP, long TO);

    //Functions
    void Timing();
    long Ranging(int sys);
    void Config();
    
  private:
    int  trigPin, echoPin;
    long timeOut, duration;
};

#endif
