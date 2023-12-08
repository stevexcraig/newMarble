//UP & DOWN LEFT RIGHT FOR NEW MARBLE MACHINE

const int motor1Pin = 5;
const int motor2Pin = 4;
const int enablePin = 3;

int updownPot = A1;
int updownValue;
int upSpeed = 255; // UP SPEED
int downSpeed = 180; //DOWN SPEED


int leftrightPot = A0;
int leftrightMax = 160; //LEFT RIGHT MAX SPEED

int motor3Pin = 7;
int motor4Pin = 8;
int enable2Pin = 6;
int leftrightSpeed;
int leftrightValue;

void setup() {

  pinMode(updownPot, INPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, HIGH);
  digitalWrite(enable2Pin, HIGH);

  pinMode(leftrightPot, INPUT);
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {


  updownValue = analogRead(updownPot);


  Serial.println(updownValue);
  if (updownValue > 900) {
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motor2Pin, LOW);
    analogWrite(enablePin, upSpeed);
  }
  if (updownValue < 100) {
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, HIGH);
    analogWrite(enablePin, downSpeed);
  }
  if ((updownValue < 600) && (updownValue > 400)) {
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, LOW);

  }

  leftrightValue = analogRead(leftrightPot);

  //Serial.println(leftrightValue);
  if (leftrightValue < 512) {
    digitalWrite(motor3Pin, HIGH);
    digitalWrite(motor4Pin, LOW);
    leftrightSpeed = (-leftrightMax / 512.) * leftrightValue + leftrightMax;
    analogWrite(enable2Pin, leftrightSpeed);
  }
  if (leftrightValue >= 512) {
    digitalWrite(motor3Pin, LOW);
    digitalWrite(motor4Pin, HIGH);
    leftrightSpeed = (leftrightMax / 512.) * leftrightValue - leftrightMax;
    analogWrite(enable2Pin, leftrightSpeed);
  }
}
