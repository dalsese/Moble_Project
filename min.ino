// #include <HardwareSerial.h>
// // #include <SoftwareSerial.h>
// #include<Wire.h>

// void setup()
// {
//     Wire.begin();
//     Serial.begin(115200);
//     while(!Serial)
//     {
        
//     }
//     delay(2000);
//     Serial.println("Program start...");
//     delay(2000);
// }

//     void loop()
//     {
//         int statusTransmission;
//         int flag=1;
//         Serial.println("I2C Device Scanning....");

//         delay(100);
//         for(int i=0; i<127; i++)
//         {
//             Wire.beginTransmission(i);
//             statusTransmission = Wire.endTransmission();
//             if(statusTransmission == 0)
//             {
//                 Serial.print("Connected I2C Device Address : 0x");
//                 if(i<16)
//                 {
//                     Serial.print("정상적으로 종료됨.");
//                 }
//                 Serial.println(i,HEX);
//                 flag = 0;
//             }
//         }
//         if(flag == 1)
//         {
//             Serial.println("No I2C devices found");
//         }
//         Serial.println("Program End...");
        
//         while(1);
//     }
