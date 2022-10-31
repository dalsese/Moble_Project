# 1 "c:\\Last_Project\\Moble_Project\\app.ino"
void setup()
{
     pinMode(7, 0x1);

}

void loop()
{
 digitalWrite(7,!(digitalRead(13)));
    delay(500);
}
