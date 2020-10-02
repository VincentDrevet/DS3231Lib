# DS3231Lib
Another Arduino DS3231 library for DS3231 RTC Clock.

Note : Commentaries in files are in french sorry for that but it should be easy to understand with example and with traduction tools and appologize for grammar english mistakes ;)


## Requirement

This library require Wire.h Library.
You must include Wire Library in your sketch :

```
#include <DS3231Device.h>
#include <Wire.h>
```

## Structure

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

## Functions

### getTime()

This function return a DeviceTime struct.

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

### setTime()

This function set time on the DS3231 device.
For do that, the function take in parameter a DeviceTime struct and return nothing.

An Exemple of how use this function : 

```
#include <DS3231Device.h>
#include <Wire.h>

// Declare DS3231Device object and DeviceTime struct
DeviceTime timetortc;
DS3231Device Device;

void setup() {
  // Start Serial and I2C Bus
  Serial.begin(9600);
  Wire.begin();

  // Format: Second, Minute, Hour
  // in this example the time on the DS3231 is set to 20:49:00
  timetortc = {byte(0), byte(49), byte(20)};

  // Setting time
  Device.setTime(timetortc);

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

