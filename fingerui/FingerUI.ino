#include <Adafruit_Fingerprint.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define LED1 15
#define LED2 5

#define DRIVEDOOR 2
#define SECONDDOOR 14
#define SEATMAIN 12
#define SEATSECO 13

Adafruit_NeoPixel led1 = Adafruit_NeoPixel(5, LED1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led2 = Adafruit_NeoPixel(5, LED2, NEO_GRB + NEO_KHZ800);

SoftwareSerial mySerial(4, 0); // 일반 디지털 핀을 시리얼 통신 포트로 사용하게 해줌
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

Servo door1, door2, seat1, seat2;


void door_OPEN()
{
  delay(100);
  door1.attach(DRIVEDOOR);
  door1.write(170); 
  delay(100);
  door1.detach();
}

void door_CLOSE()
{
  // delay(100);
  door1.attach(DRIVEDOOR);

  door1.write(5);
  delay(100);
  door1.detach();
}
void doorSide_OPEN()
{
  delay(100);
  door2.attach(SECONDDOOR);
  door2.write(170);
  delay(100);
  door2.detach();
}

void doorSide_CLOSE()
{
  delay(100);
  door2.attach(SECONDDOOR);
  door2.write(5);
  delay(100);
  door2.detach();
}
void Seat_Angle()
{
  delay(100);
  seat1.attach(SEATMAIN);
  seat1.write(90);
  delay(100);
  seat1.detach();
}

void SideSeat_Angle()
{
  delay(100);
  seat2.attach(SEATSECO);
  seat2.write(90);
  delay(100);
  seat2.detach();
}

void setup()  
{
  Serial.begin(115200); // 원래는 9600 
  finger.begin(57600);
  door_CLOSE();
  doorSide_CLOSE();
  led1.begin();  //네오픽셀을 초기화하기 위해 모든LED를 off시킨다
  led2.begin();
  led1.show(); // 램의 픽셀 데이터를 Adafruit_NeoPixel에 전송
  led2.show();

  seat1.detach();
  seat2.detach();

  while (!Serial); // For Yun/Leo/Micro/Zero/...
  delay(100);

  // Ethernet.begin(mac_addr); // 현재 루프문으로 들어감
  // if (conn.connect(server_addr, 3306, user, password))
  // {
  //   delay(1000);
  // }

  // else
  // {
  //   Serial.println("DB connection failed.");
  // }

  Serial.println("\n\nAdafruit finger detect test");


  // set the data rate for the sensor serial port

  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  finger.getTemplateCount();
  Serial.print("Sensor contains "); 
  Serial.print(finger.templateCount); 
  Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}

//255가지의 색을 나타내는 함수
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return led1.Color(WheelPos * 3, 255 - WheelPos * 3, 0), led2.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return led1.Color(255 - WheelPos * 3, 0, WheelPos * 3), led2.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return led1.Color(0, WheelPos * 3, 255 - WheelPos * 3), led2.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

//모든 LED를 출력가능한 모든색으로 한번씩 보여주는 동작을 한번하는 함수
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<led1.numPixels(); i++) {
      led1.setPixelColor(i, Wheel((i+j) & 255));
      led2.setPixelColor(i, Wheel((i+j) & 255));
    }
    led1.show();
    led2.show();
    // delay(wait);
  }
}

//NeoPixel에 달린 LED를 각각 다른색으로 시작하여 다양한색으로 5번 반복한다
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { 
    for(i=0; i< led1.numPixels(); i++) {
      led1.setPixelColor(i, Wheel(((i * 256 / led1.numPixels()) + j) & 255));
      led2.setPixelColor(i, Wheel(((i * 256 / led2.numPixels()) + j) & 255));
}
    led1.show();
    led2.show();
    // delay(wait);
  }
}

void loop()                     // run over and over again
{  
  getFingerprintIDez();
  delay(50); 
  //don't ned to run this at full speed.
}

uint8_t getFingerprintID() 
{
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      //Serial.println("Imaging error");
      return p;
    default:
      //Serial.println("Unknown error");
      return p;
  }
  // OK success!
  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      //Serial.println("Could not find fingerprint features");
      return p;
    default:
      //Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    //Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    //Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    //Serial.println("Did not find a match");
    return p;
  } else {
    //Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  // 아래의 조건문에 특정지문을 지정하여 그에 맞는 설정이 중요.
  // 현재는 지문이 저장된게 맞기만 하면 led랑 모터 구동시키는 것.

  if(finger.confidence >= 100) 
  {
    Serial.println("connect..");
    rainbow(20);
    rainbowCycle(20);
    door_OPEN(); // ??
    doorSide_OPEN();
    Seat_Angle();
    SideSeat_Angle();
    delay(10000);
    door_CLOSE(); // ??
    doorSide_CLOSE();
  }

  else
  {
    Serial.println("retouch plz.......");
    delay(100);
    door_CLOSE();
  }

  return finger.fingerID; 
}