#include "Arduino.h"
#include "DS3231Device.h"
#include "Wire.h"

/*
  Auteur : Vincent Drevet
  Librairie DS3231Device

  Librairie permettant la gestion de module RTC DS3231
*/

/*
  Le constructeur par vide par défaut de la classe
  L'attribut _addr qui représente l'adresse du module sur le bus I2C est défini en dur car celui-ci est immuable et ne peut-être changé
*/
DS3231Device::DS3231Device() {
 _addr = 0x68;
};

// Permet de récupérer l'adresse I2C du module RTC
void DS3231Device::getI2CAddr() {
  Serial.println(_addr);
}

/* 
  Fonction prenant en paramètre un byte au format bcd et le converti en byte au format décimal
  Ex: 20 au format BCD = 0010 0000 => 0001 0100 au format DEC
*/
byte DS3231Device::bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}

/*
  Fonction prenant en paramètre un byte au format decimal et le converti en byte au format bcd
  Ex: 20 au format decimal = 0001 0100 => 0010 0000
*/
byte DS3231Device::decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}

/*
  Fonction retournant une structure DeviceTime contenant le temps renvoyé par le module RTC.
  Les valeurs contenu dans la structure sont des bytes au format DEC, il n'est pas nécessaire de les convertir
*/
DeviceTime DS3231Device::getTime() {
  // On démarre la transmission
  Wire.beginTransmission(_addr);

  // On place le pointeur sur l'adresse 0
  Wire.write(0x0);

  // On requête l'esclave et on retourne 3 octets (les secondes, minutes et heures)
  Wire.requestFrom(_addr, 5);

  // On récupère les données bruts
  byte secondes = Wire.read();
  byte minutes = Wire.read();
  byte heures = Wire.read();

  // On ferme la transmission
  Wire.endTransmission();

  // On crée une struct pour retourner toutes les valeurs
  struct DeviceTime time;

  // Avant de retourné les valeurs, on converti les valeurs BCD en DEC
  time.Seconde = bcdToDec(secondes);
  time.Minute = bcdToDec(minutes);
  time.Heure = bcdToDec(heures);

  return time;
  
}
/*
  Fonction permettant de définir l'heure sur le module RTC.
  La fonction prend en paramètre une structure DeviceTime.
  La fonction appelle elle même la fonction decToBcd. Il est n'est donc pas nécessaire de convertir en amont les valeur binaire DEC en binaire BCD
*/
void DS3231Device::setTime(DeviceTime timetoset) {

  // On converti les valeurs DEC en BCD
  byte secondebcd = decToBcd(timetoset.Seconde);
  byte minutebcd = decToBcd(timetoset.Minute);
  byte heurebcd = decToBcd(timetoset.Heure);

  // On démarre la transmission
  Wire.beginTransmission(_addr);

  // On place le pointeur sur l'adresse 0
  Wire.write(0x0);

  // On écrit les secondes
  Wire.write(secondebcd);
  Wire.write(minutebcd);
  Wire.write(heurebcd);

  // On termine la transmission
  Wire.endTransmission();

  
}


