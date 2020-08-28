#include <SoftwareSerial.h> // 블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial Blue (3,2); // 블루투스 설정 bluetooth(Tx, Rx)

long int data; // android 휴대폰에서 전송된 번호 저장하는데 사용

int motorA_A1 = 10; // 모터에 연결된 디지털 변수 motorA_A1 선언
int motorA_B1 = 9; // 모터에 연결된 디지털 변수 motorA_B1 선언

long int password1 = 92; // '전원이 켜질때'의 변수값 선언
long int password2 = 79; // '불이 꺼질때'의 변수값 선언

long int weak = 10; // '약풍'일 경우의 변수 값 선언
long int middle = 50; // '중풍'일 경우의 변수 값 선언
long int strong = 80; // '강풍'일 경우의 변수 값 선언

void setup() {

  pinMode(motorA_A1, OUTPUT); // motorA_A1을 출력모드로 설정
  pinMode(motorA_B1, OUTPUT); // motorA_B1을 출력모드로 설정

  analogWrite(motorA_A1, 0); //시작할때 모터가 돌아가지 않도록 설정
  analogWrite(motorA_B1, 0);

  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
  Blue.begin(9600); // 블루투스 통신 시작
}

void loop() {

  while(Blue.available() == 0); // 블루투스에 데이터를 받지 못했다면 여기서 기다리기

  if(Blue.available() > 0) { // 블루투스에 값이 들어오면

    data = Blue.parseInt(); // 블루투스 값을 'data'에 입력
    }

    delay(400); // 0.4초 딜레이

    if(data == password1) { // 만약 데이터값과 불이 켜질때의 값이 같다면

      analogWrite(motorA_A1, 200); // 모터가 돌아가도록 설정
      analogWrite(motorA_B1, 0);

      Serial.println("DCmotor ON"); // 시리얼 모니터에 "DCmotor ON" 출력
    }

    else if(data == password2) { // 만약 데이터값과 불이 꺼질때의 값이 같다면

      analogWrite(motorA_A1, 0); // 모터가 꺼지도록 설정
      analogWrite(motorA_B1, 0);

      Serial.println("DCmotor OFF"); // 시리얼 모니터에 "DCmotor OFF" 출력
    }

    else if(data == weak) { // 만약 데이터값과 약풍으로 설정해 놓은 값이 같다면

      analogWrite(motorA_A1, 50); // 모터가 약하게 돌아가도록 설정
      analogWrite(motorA_B1, 0);

      Serial.println("Weak Wind"); // 시리얼 모니터에 "Weak Wind" 출력
    }

    else if(data == middle) { // 만약 데이터값과 중풍으로 설정해 놓은 값이 같다면

      analogWrite(motorA_A1, 120); // 모터가 중간으로 돌아가도록 설정
      analogWrite(motorA_B1, 0);

      Serial.println("Middle Wind"); // 시리얼 모니터에 "Middle Wind" 출력
    }

    else if(data == strong) { // 만약 데이터값과 강풍으로 설정해 놓은 값이 같다면

      analogWrite(motorA_A1, 220); // 모터가 강하게 돌아가도록 설정
      analogWrite(motorA_B1, 0);

      Serial.println("Strong Wind"); // 시리얼 모니터에 "Strong Wind" 출력
    }

    //임시
    else if(data == 1) {

      analogWrite(motorA_A1, 200);
      analogWrite(motorA_B1, 0);

      delay(1000);

      analogWrite(motorA_A1, 0);
      analogWrite(motorA_B1, 0);
    }
  }
