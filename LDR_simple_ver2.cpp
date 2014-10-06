//Code to use Light Dependent Light&Dark Sensor
/* There are two types of code here: Register based pulldown 
				     Software based pulldown
**Pulldown is required as the Digital Pin of Arduino, defaults to floating position
**With a pulldown we set its default state to Low, otherwise in foating state it can be anything (analogy: Superposition or value of uninitialized variable)

See code documentation for details.
Author: Prakhar Gaur
License: GNU GPL3
Date: 6 Oct 2014
Code derived from, Input Pullup Serial, by Scott Fitzgerald.
*/

//    *** 1 ***
//Code with Registor pulldown, see fzz file for circuit layout
int sensorVal, pin=3;

void setup(){
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input, anyways this is default
  pinMode(pin, INPUT);
}

void loop(){
  // read value from sensor 
  sensorVal = digitalRead(pin);
  //print out the State of sensor
  Serial.println(sensorVal);
  delay(1000);
}
//*******************************************************//

//    *** 2 ***
//Code with software based pulldown

int sensorVal, pin=3;

void setup(){
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input, anyways this is default
  pinMode(pin, INPUT);
}

void loop(){
  pinMode(pin, OUTPUT); // to pull a pin down you must set it as an output
  digitalWrite(pin, LOW); // then pull it down
  pinMode(pin, INPUT); // immediately before reading you set it as an input

  sensorVal = digitalRead(pin); //Read value from the OUT pin
  //print out the state of sensor
  Serial.println(sensorVal);
  delay(1000);
}
