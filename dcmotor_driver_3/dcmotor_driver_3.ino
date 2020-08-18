//모터 드라이버로 DC모터 양방향 제어하기

//모터 연결된 디지털핀 변수 선언 (PWM 방식)
int motorA_A1 = 10, motorA_B1 = 9;

void setup() {
  //핀 모드 설정
  pinMode(motorA_A1, OUTPUT);
  pinMode(motorA_B1, OUTPUT);
}

void loop() {
  //모터A의 A1단자에 전압을 가해주면 B1단자는 0V가 되어야함.
  analogWrite(motorA_A1, 200); //A모터, A1 단자 전압 O
  analogWrite(motorA_B1, 0); //A모터, B1 단자 전압 X
  delay(3000); //3초가 유지
  //각 바퀴 반대방향 회전
  analogWrite(motorA_A1, 0); //A모터, A1 단자 전압 X
  analogWrite(motorA_B1, 200); //A모터, B1 단자 전압 O
  delay(3000); //3초가 유지
}//모터 드라이버로 DC모터 양방향 제어하기

//모터 연결된 디지털핀 변수 선언 (PWM 방식)
int motorA_A1 = 10, motorA_B1 = 9;

void setup() {
  //핀 모드 설정
  pinMode(motorA_A1, OUTPUT);
  pinMode(motorA_B1, OUTPUT);
}

void loop() {
  //모터A의 A1단자에 전압을 가해주면 B1단자는 0V가 되어야함.
  analogWrite(motorA_A1, 200); //A모터, A1 단자 전압 O
  analogWrite(motorA_B1, 0); //A모터, B1 단자 전압 X
  delay(3000); //3초가 유지
  //각 바퀴 반대방향 회전
  analogWrite(motorA_A1, 0); //A모터, A1 단자 전압 X
  analogWrite(motorA_B1, 200); //A모터, B1 단자 전압 O
  delay(3000); //3초가 유지
}
