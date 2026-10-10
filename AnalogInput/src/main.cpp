//Joyce Adeyi 
//COMP 
#include <Arduino.h>

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal;

  //read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);
  float voltage = (iVal /1023.0) * 3.3;
  float temperature = (iVal /1023.0) * 50.0;

  //determine the temperature judgement
  String judgement;

  if (temperature < 10.0){
    judgement = "Cold!";
  }
  else if (temperature < 15.0){
    judgement = "Cool";
  }
  else if (temperature < 25.0){
    judgement = "Perfect";
  }
  else if (temperature < 30.0){
    judgement = "Warm";
  }
  else{
    judgement = "Too Hot!";
  }

  //Print the temperature and judgement 
  Serial.print("Digitized output of ");
  Serial.print(iVal);
  Serial.print(" is equivalent to a temperature input of ");
  Serial.print(temperature, 2);
  Serial.print(" C, which is ");
  Serial.println(judgement);

  //wait 2 second
  delay(2000);
}
