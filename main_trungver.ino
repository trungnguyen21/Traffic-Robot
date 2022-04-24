int motor1Positive = 5;       //2 động cơ bên phải
int motor1Negative = 4;

int motor2Positive = 3;       //2 động cơ bên trái
int motor2Negative = 2;

int callValue;
#define call 30

int  giatri1 ; //Đọc giá trị cảm biến s1 và gán vào biến giatri1
int  giatri2;
int  giatri3;
int  giatri4;
int  giatri5;
int signal;

int distanceLeft;
int distanceRight;
int distanceFront;
int distanceBack;

// do line
int s1 = 11; // Cảm biến trái ngoài cùng
int s2 = 10;
int s3 = 9; // Cảm biến giữa
int s4 = 8;
int s5 = 7; // Cảm biến phải ngoài cùng


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(motor1Positive, OUTPUT);
  pinMode(motor1Negative, OUTPUT);
  pinMode(motor2Positive, OUTPUT);
  pinMode(motor2Negative, OUTPUT);
  pinMode(call, INPUT_PULLUP);


  //do line

  pinMode(s1, INPUT); //Cảm biến nhận tín hiệu
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  // cam bien sieu am (trc sau)

  // cam bien sieu am (2 ben)

}

void sensorFrontBack()
{
  // TO-DO
}

void sensorLeftRight()
{
  // TO-DO
}

void turnRight() {
  digitalWrite(motor1Positive, HIGH);
  digitalWrite(motor1Negative, LOW);
  digitalWrite(motor2Positive, HIGH);
  digitalWrite(motor2Negative, LOW);
}

void turnLeft() {
  digitalWrite(motor1Positive, LOW);
  digitalWrite(motor1Negative, HIGH);
  digitalWrite(motor2Positive, LOW);
  digitalWrite(motor2Negative, HIGH);
}

void goForward() {
  digitalWrite(motor2Positive, HIGH);
  digitalWrite(motor2Negative, LOW);
  digitalWrite(motor1Positive, LOW);
  digitalWrite(motor1Negative, HIGH);
}

void goBackward() {
  digitalWrite(motor2Positive, LOW);
  digitalWrite(motor2Negative, HIGH);
  digitalWrite(motor1Positive, HIGH);
  digitalWrite(motor1Negative, LOW);
}

void stop() {
  digitalWrite(motor1Positive, LOW);
  digitalWrite(motor1Negative, LOW);
  digitalWrite(motor2Positive, LOW);
  digitalWrite(motor2Negative, LOW);
}

void loop()
{
  sensorFrontBack();
  sensorLeftRight();
  int  giatri1 = digitalRead(s1); //Đọc giá trị cảm biến s1 và gán vào biến giatri1
  int  giatri2 = digitalRead(s2);
  int  giatri3 = digitalRead(s3);
  int  giatri4 = digitalRead(s4);
  int  giatri5 = digitalRead(s5);

  
  if ((digitalRead(call) == 0) || (distanceBack > 50) || ((distanceLeft < 50) && (distanceRight < 50)))
  {
    stop(); 
  }
  else if ((giatri2 == 0) && (giatri3 == 0) && (giatri4 == 0))
  {
    goForward();
    if ((distanceLeft <= 100) || (distanceRight <= 100) || (distanceFront <= 100))
    {
      // KEU
    }
  }
  else if ((giatri2 == 1) && (giatri3 == 1) && (giatri4 == 1))
  {
    turnLeft();
    if (digitalRead(call) == 0 || (distanceBack > 50))
    {
      stop();
    }
  }

  
//  Serial.print("S2: ");
//  Serial.print(giatri2); Serial.print("   ");
//  Serial.print("S3: ");
//  Serial.print(giatri3); Serial.print("   ");
//  Serial.print("S4: ");
//  Serial.print(giatri4); Serial.print("   ");
//  Serial.println(digitalRead(call));
  if (digitalRead(call) == 1 || (distanceBack < 50)) {
    if ((giatri2 == 0) && (giatri3 == 0) && (giatri4 == 0)) {
      Serial.print("Di thang");
      goForward();
    } else if ((giatri2 == 1) && (giatri3 == 1) && (giatri4 == 1)) {
      stop();
      Serial.println("stop1");
    }
  } else if (digitalRead(call) == 0) {
    stop();
    Serial.println("stop2");
  }
}
