int s1 = 11; //Cảm biến nối chân số 2 Arduino
int s2 = 10;
int s3 = 9;
int s4 = 8;
int s5 = 7;
int congtac = 13; //CLP
int hongngoai = 12; //Near

int giatri1, giatri2, giatri3, giatri4, giatri5, gtcongtac, gthongngoai;

void setup() 
{
  Serial.begin(9600);

  pinMode(s1, INPUT); //Cảm biến nhận tín hiệu
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(congtac, INPUT);
  pinMode(hongngoai, INPUT);

}

void loop() 
{  
  giatri1 = digitalRead(s1); //Đọc giá trị cảm biến s1 và gán vào biến giatri1
  giatri2 = digitalRead(s2);
  giatri3 = digitalRead(s3);
  giatri4 = digitalRead(s4);
  giatri5 = digitalRead(s5);
  gtcongtac = digitalRead(congtac);
  gthongngoai = digitalRead(hongngoai);
  
  Serial.print("S1: ");
  Serial.print(giatri1);Serial.print("   ");
  Serial.print("S2: ");
  Serial.print(giatri2);Serial.print("   ");
  Serial.print("S3: ");
  Serial.print(giatri3);Serial.print("   ");
  Serial.print("S4: ");
  Serial.print(giatri4);Serial.print("   ");
  Serial.print("S5: ");
  Serial.print(giatri5);Serial.print("   ");
  Serial.print("Công tắc: ");
  Serial.print(gtcongtac);Serial.print("   ");
  Serial.print("Hồng ngoại: ");
  Serial.println(gthongngoai);  
  delay(200);

}
