#include <SoftwareSerial.h> // 블루투스 시리얼 통신 라이브러리 추가

SoftwareSerial Blue(5,6); // 블루투스 설정 bluetooth(Tx, Rx)

long int data; // 값을 입력받을 데이터 값

int DCmotor = 11; // 'DC모터' 변수 선언
long int password1 = 92; // '전원이 켜질 때'의 변수값 선언
long int password2 = 79; // '전원이 꺼질 때'의 변수값 선언

char state = 0;

void setup()
{
  
  pinMode(DCmotor, OUTPUT); // DC모터를 출력모드로 설정
  analogWrite(DCmotor, HIGH); // DC모터가 꺼짐 (현재 아두이노가 값을 입력하면 반대로 읽히기 때문에 반대로 값을 입력한 상태)

  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
  Blue.begin(9600); // 블루투스 통신 시작
  
}

void loop()
{

  while(Blue.available()==0); // 블루투스에서 데이터를 받지 못했다면 여기서 기다리기

  if(Blue.available()>0) { // 블루투스에 값이 들어왔을 경우
    data = Blue.parseInt(); // 블루투스 값을 'data'에 입력
  }

  delay(400); // 0.4초 딜레이

  if (data == password1) { // 만약 데이터 값과 전원이 들어왔을때의 값이 같다면
    analogWrite(DCmotor, 0); // 모터의 세기를 최대로 설정
    Serial.println("DCmotor ON"); // 시리얼 모니터에 "DCmotor ON" 출력
  }

  if (data == password2) { // 만약 데이터 값과 전원이 꺼졌을때의 값이 같다면
    analogWrite(DCmotor, 255); // 모터의 세기를 최하로 설정
    Serial.println("DCmotor OFF"); // 시리얼 모니터에 "DCmotor OFF" 출력
  }
}
