int leftTrig = 49;
int leftEcho = 48;
int rightTrig = 51;
int rightEcho = 50;

unsigned int leftDistance, rightDistance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftTrig, OUTPUT);
  pinMode(rightTrig, OUTPUT);
  digitalWrite(leftTrig, HIGH);
  digitalWrite(rightTrig, HIGH);
  pinMode(leftEcho, INPUT);
  pinMode(rightEcho, INPUT);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance Left = ");
  digitalWrite(leftTrig, LOW);
  digitalWrite(leftTrig, HIGH);

  unsigned long LowLevelTimeLeft  = pulseIn(leftEcho, LOW);

  Serial.print("Distance Right = ");
  digitalWrite(rightTrig, LOW);
  digitalWrite(rightTrig, HIGH);

  unsigned long LowLevelTimeRight  = pulseIn(rightEcho, LOW);

  if (LowLevelTimeRight >= 50000) {
    Serial.println("Invalid");
  } else {
    rightDistance = LowLevelTimeRight / 50;
    Serial.print(rightDistance);
    Serial.println(" cm");
  }
  
  if (LowLevelTimeLeft >= 50000) {
    Serial.println("Invalid");
  }
  else
  {
    leftDistance = LowLevelTimeLeft / 50;
    Serial.print(leftDistance);
    Serial.println(" cm");
  }

  if ((leftDistance <= 600) && (leftDistance >= 200) || (rightDistance <= 600) && (rightDistance >= 200)) {
    stop();
  } else {
    goForward();
  }
  
  delay(500);
}
