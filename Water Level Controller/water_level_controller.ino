
int relayPin = 8;
int trigPin = 4;
int echoPin = 5;
int redLED = 3;
int greenLED = 2;
int time;
float distance;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);

}

void loop() {
digitalWrite(trigPin, HIGH); 
  delayMicroseconds(5); 
  digitalWrite(trigPin, LOW); 
  int time = pulseIn(echoPin, HIGH);
  
  float distance = (time*0.034)/2;
  float height = 200 - distance;

  Serial.println(height);

  if ((height >= 0) && (height < 180)) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(relayPin, HIGH);
  }

  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(relayPin, LOW);
  }
}