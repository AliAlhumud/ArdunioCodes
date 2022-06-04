#include <ESP32Servo.h>
 
Servo myservo;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32
int IRSensor = 35;
int IRSensor2 = 34;
int Sensor_1 = 0;
int Sensor_2 = 0;
int start = 0;
int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin = 14;
 
void setup() {
  Serial.begin(9600);
    pinMode(IRSensor, INPUT);
     pinMode(IRSensor2, INPUT);
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 500, 2400); // attaches the servo on pin 18 to the servo object

}
 
void loop() {
	  Sensor_1 = digitalRead(IRSensor); 
    Sensor_2 = digitalRead(IRSensor2); 
	   
if ((Sensor_1 == 0 )  && (Sensor_2 == 1)){
start = 1;
    	delay(15);  
  }

  if ((start == 1)  && (Sensor_2 == 1)) {
  myservo.write(0); 
    Serial.println("start moving"); 
    	delay(15);  
      }
  if (Sensor_2 == 1){
        start = 0;
            Serial.println("Take your order");
      }
  else{
      myservo.write(90); 
    	delay(15);  

      }
}