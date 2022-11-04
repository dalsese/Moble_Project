#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <stdio.h>

const char* ssid     = "moble_main_2.4G";
const char* password = "12345678";
String host = "http://35.74.75.58/";

const long interval = 5000;
unsigned long previousMillis = 0;

WiFiClient client;
HTTPClient http;

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Connect to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    String phpHost = host+"/test2.php?uf=aasd&un=str"; // 데이터 전송하는 코드! 뒤에 str이 전송.
    Serial.print("Connect to ");
    Serial.println(phpHost);
    
    http.begin(client, phpHost); // http에 보내겠다
    http.setTimeout(1000);
    int httpCode = http.GET();
   
    if(httpCode > 0) {
      Serial.printf("GET code : %d\n\n", httpCode);
 
      if(httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } 
    else {
      Serial.printf("GET failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
}