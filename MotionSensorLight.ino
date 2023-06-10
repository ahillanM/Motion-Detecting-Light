/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/
 
int light = 8;                // the pin that the light is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(light, OUTPUT);      // initalize light as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(light, HIGH);   // turn light ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(light, LOW); // turn light OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        state = LOW;       // update variable state to LOW
    }
  }
}
