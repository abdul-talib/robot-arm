
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

// the code inside loop() 
void loop() {


for(int i=0; i<16; i++)
  {
    for( int angle =0; angle<181; angle +=10){
      delay(500);
      //Point A
        pwm.setPWM(0, 0, angleToPulse(0) );
        delay(2000);
        pwm.setPWM(1, 0, angleToPulse(120) );
        delay(2000);
        pwm.setPWM(2, 0, angleToPulse(180) );
        delay(2000);
        
        pwm.setPWM(3, 0, angleToPulse(120) );
        delay(2000);
         pwm.setPWM(4, 0, angleToPulse(120) );
        delay(2000);
         
         pwm.setPWM(5, 0, angleToPulse(128) );
        delay(3000);
        
        
        pwm.setPWM(2, 0, angleToPulse(90) );
        delay(2000);

      //Point B  
        pwm.setPWM(0, 0, angleToPulse(130) );
        delay(3000);
        pwm.setPWM(2, 0, angleToPulse(180) );
        delay(3000);

       pwm.setPWM(5, 0, angleToPulse(80) );
        delay(3000);

        pwm.setPWM(2, 0, angleToPulse(90) );
        delay(5000);
        
        
        
              
    }
 
  }
 
  
  delay(1000);// wait for 1 second
 
}


 
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
