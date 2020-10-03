#ifndef DS3231Device_h
#define DS3231Device_h

#include "Arduino.h"

/*
  Auteur : Vincent Drevet
  Librairie DS3231Device

  Librairie permettant la gestion de module RTC DS3231
*/

// Structure DeviceTime utilisé pour stocker les données temporelles du module
struct DeviceTime
{
  byte Seconde;
  byte Minute;
  byte Heure;
  String JSemaine;
};

class DS3231Device {
  public:
    // Constructeur vide
    DS3231Device();

    // Les méthodes de la classe
    void getI2CAddr();
    DeviceTime getTime();
    byte bcdToDec(byte bcd);
    byte decToBcd(byte dec);
    void setTime(DeviceTime timetoset);
    

    // L'adresse du Module RTC sur bus I2C
    private:
      String byteToJSemaine(byte bJSemaine);
      byte StringJSemaineTobyte(String JSemaine);
      int _addr;
};


#endif
