#include <Arduino.h>
#line 1 "c:\\Last_Project\\Moble_Project\\app.ino"
#line 1 "c:\\Last_Project\\Moble_Project\\app.ino"
void setup();
#line 7 "c:\\Last_Project\\Moble_Project\\app.ino"
void loop();
#line 1 "c:\\Last_Project\\Moble_Project\\app.ino"
void setup()
{
	    pinMode(7, OUTPUT);

}

void loop()
{
	digitalWrite(7,!(digitalRead(13)));
    delay(500);
}

