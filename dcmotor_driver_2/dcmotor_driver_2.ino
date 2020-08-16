#include <SoftwareSerial.h> // 블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial Blue(3, 2); // 블루투스 설정 bluetooth(Tx, Rx)

int in1 = 7; // in1을 7번포트에 연결
int in2 = 5; // in2를 5번 포트에 연결

long int password1 = 92; // '전원이 켜질 때'의 변수값 선언
long int password2 = 79; // '전원이 꺼질 때'의 변수값 선언

void setup() {

  pinMode(in1, OUTPUT); // in1을 출력모드로 설정
  pinMode(in2, OUTPUT); // in2를 출력모드로 설정

  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
  Blue.begin(9600); // 블루투스 통신 시작
}

void loop() {

  while(Blue.available() == 0); // 블루투스에서 데이터를 받지 못했다면 여기서 기다리기

  if(Blue.available()) { // 만약 블루투스에서 데이터가 들어왔을 경우

    char in_data; // 데이터가 들어온 값을 저장할 변수 in_data
    in_data = Blue.read(); // 블루투스에서 들어온 값을 in_data에 입력

    if(in_data == password1) { // 만약 데이터 값과 전원이 들어왔을때의 값이 같다면

      digitalWrite(in1, HIGH); // in1을  HIGH로 설정
      digitalWrite(in2, LOW); // in2를 LOW로 설정

      Serial.println("DCmotor ON"); // 시리얼 모니터에 "DCmotor ON" 출력
    }

    else if(in_data == password2) { // 만약 데이터 값과 전원이 꺼졌을때의 값이 같다면 

      digitalWrite(in1, LOW); // in1을 LOW로 설정
      digitalWrite(in2, LOW); // in2를 LOW로 설정

      Serial.println("DCmotor OFF"); // 시리얼 모니터에 "DCmotor OFF" 출력
    }
  }
}
