const int trigPin = 8;
const int echoPin = 7;
const int redLedPin = 2;    // Red LED pin
const int greenLedPin = 12; // Green LED pin
const int buzzerPin = 4;    // Digital pin connected to the buzzer

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance >= 6 && distance <= 15) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    delay(100);  // Adjust the delay as needed
    noTone(buzzerPin);
  } else if (distance < 6) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    tone(buzzerPin, 1000);  // Adjust the frequency as needed
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    noTone(buzzerPin);
  }

  delay(500);
}