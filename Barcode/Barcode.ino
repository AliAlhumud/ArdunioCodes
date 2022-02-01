
#define RXD1 18
#define TXD1 19
#define RXD2 16
#define TXD2 17


HardwareSerial Serial2(2);


void setup()
{

 Serial2.begin(9600, SERIAL_8N1, 16, 17);

}
 void loop()
 {

while(Serial2.available()) Serial.println(char(Serial2.read()));

//if (Serial1.available()) {      // If anything comes in Serial (USB),
    //Serial2.write(Serial1.read());   // read it and send it out Serial1 (pins 0 & 1)
  }

  //if (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    //Serial1.write(Serial2.read());   // read it and send it out Serial (USB)
 // }

   
 //}