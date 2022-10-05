void setup()
{
	    pinMode(7, OUTPUT);

}

void loop()
{
	digitalWrite(7,!(digitalRead(7)));
    delay(500);
}
