// // #define ledPin 7
// // #include <Wire.h>

// // void setup()
// // {
// //     pinMode(ledPin, OUTPUT);
// //     Wire.begin(0x60);
// //     Wire.onReceive(receiveEvent);
// // }

// // void loop()
// // {
// //     delay(500);
// // }

// // void receiveEvent(int howMany)
// // {
// //     byte value;

// //     while(0 < Wire.available())
// //     {
// //         value = Wire.read();
// //     }

// //     if(value == 1)
// //     {
// //         digitalWrite(ledPin, HIGH);
// //     }

// //     else
// //     {
// //         digitalWrite(ledPin, LOW);
// //     }

// // }

// #include <Wire.h>

// void setup ()
// {
//     Wire.begin(0x60);
//     Wire.onReceive(receiveEvent);
// }

// void loop()
// {

// }

// void receiveEvent(int parameter)
// {
//     while(Wire.available() > 0)
//     {
//         char a = Wire.read();
//         Serial.print(a);
//         Serial.print(" ");
//     }
// }