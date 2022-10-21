// #include <ESP8266WiFi.h>

// const char* ssid = "http://35.74.75.58/";
// const char* password = "password"

// int LED = 2; 

// WiFiServer server(80);

// void setup() {
//   // put your setup code here, to run once:
//   delay(10);
//   Serial.begin(115200); //시리얼 통신 속도

//   Serial.println();
//   Serial.println();
//   Serial.println("connecting to my ssid.");
  
//   WiFi.begin(ssid, password);
  
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.println(".");
//   }
//   Serial.println("");
//   Serial.println("WiFi connected");

//   // start the server
//   server.begin();
//   Serial.println("Server started");
//   Serial.println("Use this URL to connect");
//   Serial.print("http://");
//   Serial.print(WiFi.localIP());
//   Serial.println("/");

  
  
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   WiFiClient client = server.available();
//   if(!client){
//     return;
//   } else {
//     Serial.println("New client connect...");
//     boolean blank_line = true;
//     while(client.connected()){
//       char c = client.read();
//       if (c == '\n' && blank_line) {
        
//         // We have read the request of the client. Now send the page
        
//         client.println("HTTP/1.1 200 OK");
//         client.println("Content-Type: text/html");
//         client.println("Connection: close");
//         client.println();
//         client.println("<!DOCTYPE HTML>");
//         client.println("<html>");
//         client.println("<head><title>NodeMCU Websever</title>");
//         client.println("<meta http-equiv=\"Content-Type\" Content=\"text/html; charset=utf-8\">");
//         client.println("<meta name=\"viewport\" content=\"width=device-width, user-scalable=no\">");
//         //스타일추가
//         client.println("<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\">");
//         client.println("<style type=\"text/css\"><!--");
//         client.println("body {font-size:11pt;}");
//         client.println("h3 {color: #85144b; font-size: 14pt;}");
//         client.println("#footer {text-align: center; margin-top: 20px;}");
//         client.println("#footer p {font-size: 9pt; color: #85144b;}");
//         client.println("//--></style>");
//         //자바스크립트 추가
//         client.println("<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js\"></script>");
//         client.println("<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\"></script>");
//         client.println("</head>");
//         client.println("<body>");
//         //페이지 본문 추가
//         client.println("<div class=\"container\"><h3>NodeMCU Webserver</h3>");
//         client.println("<img src=\"http://data/file/gallery/32578099_6FICMc9X_079_olaf_snowman.png\" class=\"img-rounded\" alt=\"Cinque Terre\" width=\"320\">");
//         client.println("<div><br>NodeMCU에서 돌아가는 웹서버입니다. <br>부트스트랩도 사용이 가능합니다. 웹브라우저로 접속해서 각종 센서 데이터를 출력하거나 디바이스를 컨트롤 할 수 있습니다.<br><br></div>");
//         client.println("<button type=\"button\" class=\"btn btn-default\">부트스트랩</button>");
//         client.println("<button type=\"button\" class=\"btn btn-primary\">버튼 모양</button>");
//         client.println("<button type=\"button\" class=\"btn btn-danger\">확 인</button>");

//         client.println("<h2>Monitoring</h2><ul class='nav nav-tabs'><li class='active'><a data-toggle='tab' href='#home'>Home</a></li><li><a data-toggle='tab' href='#menu1'>온도/습도</a></li>");
//         client.println("<li><a data-toggle='tab' href='#menu2'>LED</a></li><li><a data-toggle='tab' href='#menu3'>DC모터</a></li></ul>");
        
//         client.println("<div class='tab-content'><div id='home' class='tab-pane fade in active'><h3>안내</h3><p>보드에 연결된 각종 센서의 체크할 수 있습니다. <br>각각의 탭을 선택하시기 바랍니다.</p></div>");
//         client.println("<div id='menu1' class='tab-pane fade'><h3>온도/습도</h3><p>온도,습도 센서의 값을 확인합니다.</p></div>");
//         client.println("<div id='menu2' class='tab-pane fade'><h3>LED</h3><p>LED를 켜고 끕니다.</p></div>");
//         client.println("<div id='menu3' class='tab-pane fade'><h3>DC모터</h3><p>DC모터를 작동 시켜 봅니다.</p></div>");
//         client.println("</div>");
        
//         //하단 카피라이트
//         client.println("<div id='footer'><p>Copyright 2017 by cosmos. All Rights Reserved.</p></div>");
//         client.println("</div></body></html>");  
//         break;
//       }
//       if (c == '\n') {
//         blank_line = true;
//       } else if (c!= '\r') {
//         blank_line = false;
//       }   
//     }
//   }
//   delay(1);
//   client.stop();
//   Serial.println("Client disconnected");
// }