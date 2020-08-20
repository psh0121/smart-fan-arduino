//모터 드라이버로 DC모터 양방향 제어하기

//모터 연결된 디지털핀 변수 선언 (PWM 방식), in1은 10번포트 in2는 5번포트에 연결
int motorA_A1 = 10, motorA_B1 = 9;

void setup() {
  
  pinMode(motorA_A1, OUTPUT); // motorA_A1을 출력모드로 설정
  pinMode(motorA_B1, OUTPUT); // motorA_B1을 출력모드로 설정
}

void loop() {
  
  // 모터A의 A1단자에 전압을 가해주면 B1단자는 0V가 되어야함
  // 전압이 이동하면서 모터가 돌아가도록 함
  analogWrite(motorA_A1, 200); //A모터, A1 단자 전압 O
  analogWrite(motorA_B1, 0); //A모터, B1 단자 전압 X
  delay(3000); //3초간 유지
  
  // 각 바퀴 반대방향 회전
  // 모터의 전압의 방향을 반대로 작성해줌
  analogWrite(motorA_A1, 0); //A모터, A1 단자 전압 X
  analogWrite(motorA_B1, 200); //A모터, B1 단자 전압 O
  delay(3000); //3초간 유지
}//모터 드라이버로 DC모터 양방향 제어하기
