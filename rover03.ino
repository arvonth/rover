// rover
// Use an arduino, a motor shield and a xbee shield
// to drive an actobotics runt rover.  With another
// xbee connected to a PC you can send characters to
// control the motor shield.

//Includes
#include "MotorDriver.h"

//Variable
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup()
{
	/*Configure the motor A to control the wheel at the left side.*/
	/*Configure the motor B to control the wheel at the right side.*/
	motordriver.init();
	motordriver.setSpeed(255,MOTORB);
	motordriver.setSpeed(255,MOTORA);

  //Setup communications
  Serial.begin(57600);
  delay(250);
  Serial.write("\r\n>");
}
 
void loop()
{
  if(Serial.available() > 0) {
    int inByte = Serial.read();

    switch (inByte) {
      case 's':
      case 'S':
        motordriver.stop();
        Serial.write("\r\nSTOP\r\n>");
        break;
        
      case 'f':
      case 'F':
        motordriver.stop();
        delay(100);
        motordriver.goForward();
        Serial.write("\r\nFORWARD\r\n>");
        break;
        
      case 'b':
      case 'B':
        motordriver.stop();
        delay(100);
        motordriver.goBackward();
        Serial.write("\r\nBACKWARD\r\n>");
        break;
        
      case 'r':
      case 'R':
        motordriver.stop();
        motordriver.setSpeed(255,MOTORB);
        motordriver.setSpeed(255,MOTORA);
        delay(100);
        motordriver.goRight();
        Serial.write("\r\nROTATE: RIGHT\r\n>");
        break;
        
      case 'l':
      case 'L':
        motordriver.stop();
        motordriver.setSpeed(255,MOTORB);
        motordriver.setSpeed(255,MOTORA);
        delay(100);
        motordriver.goLeft();
        Serial.write("\r\nROTATE: LEFT\r\n>");
        break;
        
       case 'v':
        motordriver.setSpeed(127,MOTORB);
        motordriver.setSpeed(127,MOTORA);
        Serial.write("\r\nSPEED SET: 127\r\n>");
        break;
        
      case 'V':
        motordriver.setSpeed(255,MOTORB);
        motordriver.setSpeed(255,MOTORA);
        Serial.write("\r\nSPEED SET: 255\r\n>");
        break;
 
      case 'p':
      case 'P':
        Serial.write("\r\nRUNT ROVER 03\r\n>");
        break;
        
      default:
        break;
    }
  }
}
