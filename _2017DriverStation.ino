#include "UnoJoy.h"

/*
*not real values
*/

//buttons
int button1 = 0;
int button2 = 1;
int button3 = 2;
int button4 = 3;
int button5 = 4;
int button6 = 5;
int button7 = 6;
int button8 = 7;
int button9 = 8;
int button10 = 9;

//default
int store = 4;

//balls
int loadBalls = 12;
int scoreBalls = 7;
int rollerForwards = 6;
int rollerReverse = 5;

//gears
int loadGear = 3;
int scoreGear = 2;

//climber
int deployClimber = 9;
int climpUp = 11;
int climbDown = 10;

void setup() {

  pinMode(store, INPUT_PULLUP);
 
  pinMode(loadBalls, INPUT_PULLUP);
  pinMode(scoreBalls, INPUT_PULLUP);
  pinMode(rollerForwards, INPUT_PULLUP);
  pinMode(rollerReverse, INPUT_PULLUP);
  
  pinMode(loadGear, INPUT_PULLUP);
  pinMode(scoreGear, INPUT_PULLUP);
   
  pinMode(deployClimber, INPUT_PULLUP);
  pinMode(climbUp, INPUT_PULLUP);
  pinMode(climbDown, INPUT_PULLUP);
  
  setupUnoJoy();
  
}


void loop() {
  //Megajoy setup stuff, calls controller setup method
  dataForController_t controllerData = getControllerData();
  //controllerData.buttonArray[2] |= (HIGH << 7);
  setControllerData(controllerData);
}

dataForController_t getControllerData(void) {

  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins

  //sets directinput pins to current OI button outputs

  controllerData.buttonArray = (!digitalRead(store) << button1);
  controllerData.buttonArray |= (!digitalRead(loadBalls) << button2);
  controllerData.buttonArray |= (!digitalRead(scoreBalls) << button3);
  controllerData.buttonArray |= (!digitalRead(rollerForwards) << button4);
  controllerData.buttonArray |= (!digitalRead(rollerReverse) << button5);
  controllerData.buttonArray |= (!digitalRead(loadGear) << button6);
  controllerData.buttonArray |= (!digitalRead(scoreGear) << button7);
  controllerData.buttonArray |= (!digitalRead(deployClimber) << button8);
  controllerData.buttonArray |= (!digitalRead(climbUp) << button9);
  controllerData.buttonArray |= (!digitalRead(climbDown) << button10); 

  /*
  // Test here, the UnoJoy interface will not work
   // with this enabled
   for (int i = 2; i <= 10; i++){
   if(!digitalRead(i)){
   Serial.println("on:");
   Serial.print(i);
   }
   //    digitalWrite(i, HIGH);
   }*/

  //Sets analog axis equal to slider value
  //Megajoy looks for an 8 bit analog value but the analogRead() function returns a 10 bit value
  //Mapping sensorValue to a range of 0-255 will ensure an 8 bit value is returned

  // And return the data!
  return controllerData;

}


//copy of Arduino map function that will return a float instead of an int
float mapAsFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
