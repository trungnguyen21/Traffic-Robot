int s1 = 11; // Cảm biến trái ngoài cùng
int s2 = 10;
int s3 = 9; // Cảm biến giữa
int s4 = 8;
int s5 = 7; // Cảm biến phải ngoài cùng
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

// Code return 1 hoặc 0 để xác định có chạy hay ko để link với function chạy motor
// Do chỉ băng qua đường (assume đường thẳng) nên chắc không cần các trường hợp rẽ hay ko
int loop() 
{  
  giatri1 = digitalRead(s1); //Đọc giá trị cảm biến s1 và gán vào biến giatri1
  giatri2 = digitalRead(s2);
  giatri3 = digitalRead(s3);
  giatri4 = digitalRead(s4);
  giatri5 = digitalRead(s5);
  
  // hiện giờ t chưa biết hồng ngoại với công tắc như nào
  gtcongtac = digitalRead(congtac);
  gthongngoai = digitalRead(hongngoai);
  
  // Đọc được line trả giá trị 1, else 0
  
  if (!giatri1) & (giatri2) & (!giatri3) & (giatri4) & (!giatri5)
  {
    return 1; // Line có 2 đường thằng mà chỉ khi sensor số 2 và 4 đọc thì mới chạy, còn 3 cái còn lại ko 
  }
  else
  {
    return 0; // Có thể thêm các warning dùng loa âm thanh (hoặc robot tự chỉnh - complex hơn)
  }
  delay(200);

}
