
const int buzzer = 9; //buzzer to arduino pin 9
int sensePin = A0; //This is the Arduino Pin that will read the sensor output
int sensorInput; //The variable we will use to store the sensor input
double temp; //The variable we will use to store temperature in degrees.
#define pirPin 7
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;
void setup(){
 Serial.begin(9600); //Start the Serial Port at 9600 baud (default)
 pinMode(pirPin, INPUT);
 pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}
void loop(){
sensorInput = analogRead(A0); //read the analog sensor and store it
temp = (double)sensorInput / 1024; //find percentage of input reading
temp = temp * 5; //multiply by 5V to get voltage
temp = temp-0.5 ; //Subtract the offset
temp = temp * 100; //Convert to degrees
if(temp > 60){
 tone(buzzer, 1000); // Send 1KHz sound signal...
 delay(1000); // ...for 1 sec
 noTone(buzzer); // Stop sound...
 delay(1000);} // ...for 1sec
Serial.print("Current Temperature: ");
Serial.println(temp);
 PIRSensor();
}
void PIRSensor() {
 if(digitalRead(pirPin) == HIGH) {
 Serial.print("Motion Detected");
 tone(buzzer, 2000); // Send 1KHz sound signal...
 delay(1000); // ...for 1 sec
 noTone(buzzer); // Stop sound...
 delay(1000);} // ...for 1sec
 }
