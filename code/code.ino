// defines pins numbers
const int trigPin = 10;
const int echoPin = 9;
const int LED_1 = 2;
const int LED_2 = 6;
const int buzzer = 4;
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(LED_1, OUTPUT);
pinMode(LED_2, OUTPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if (distance <= 10){
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  tone(buzzer, 1000);
  }
else if(distance <= 25){
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);
  noTone(buzzer);
  }

else{
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  noTone(buzzer);
  }
}
