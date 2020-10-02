# DS3231Lib
Another Arduino DS3231 library for DS3231 RTC Clock


# Requirement

This library require Wire.h Library.
You must include Wire Library in your sketch :

```
#include <DS3231Device.h>
#include <Wire.h>
```

# Structure

DeviceTime : this struct is used for contain return time from DS3231 and for set time.

This struct is returned by the getTime() function and is a parameter of the setTime() function.

This is the struct definition :

```
struct DeviceTime
{
  byte Seconde;
  byte Minute;
  byte Heure;
};
```

# Functions

getTime() : This function return a DeviceTime struct.

An Exemple of how use this function : 

```
#include <DS3231Device.h>
#include <Wire.h>

// Declare DS3231Device object and DeviceTime struct
DeviceTime timefromrtc;
DS3231Device Device;

void setup() {
  // Start Serial and Wire for I2C
  Serial.begin(9600);
  Wire.begin();

}

void loop() {
  // Get Time every second
  delay(1000);
  timefromrtc = Device.getTime();

  Serial.print(timefromrtc.Heure);
  Serial.print(":");
  Serial.print(timefromrtc.Minute);
  Serial.print(":");
  Serial.println(timefromrtc.Seconde);
}
```
