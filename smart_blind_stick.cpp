// -------- Pin Definitions --------
#define trigPin 9
#define echoPin 10
#define irPin 2

#define buzzer 8
#define motor 7
#define led 6

long duration;
int distance;

void setup() {
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  // Ultrasonic distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.034 / 2;

  // IR sensor check
  int irCount = 0;
  for (int i = 0; i < 3; i++) {
    if (digitalRead(irPin) == LOW) {
      irCount++;
    }
    delay(5);
  }

  // Obstacle detection condition
  if ((distance > 0 && distance <= 50) || irCount >= 2) {

    // Turn all devices ON
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
    digitalWrite(led, HIGH);

  } else {

    // Turn all devices OFF
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
    digitalWrite(led, LOW);
  }

  delay(100);
}
