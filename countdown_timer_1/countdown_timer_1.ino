long int data; // 타이머 시간 입력받을 테이터 변수

int motorA_A1 = 10; // 모터에 연결된 디지털 변수 motorA_A1 선언
int motorA_B1 = 9; // 모터 연결된 디지털 변수 motorA_B1 선언

void setup() {

  pinMode(motorA_A1, OUTPUT); // motorA_A1을 출력모드로 설정
  pinMode(motorA_B1, OUTPUT); // motorA_B1을 출력모드로 설정

  analogWrite(motorA_A1, 0); // 시작할때 모터가 돌아가지 않도록 설정
  analogWrite(motorA_B1, 0);

  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
}

void loop() {

  while(Serial.available() == 0); // 시리얼통신에 데이터를 받지 못했다면 여기서 기다리기

  if(Serial.available() > 0) { // 시리얼통신에 값이 들어오면

    data = Serial.parseInt(); // 시리얼에서 받은 값은 'data'에 입력
  }

  if(data > 0) { // data값이 0보다 클 경우
    
    analogWrite(motorA_A1, 200); // 모터가 돌아가도록 설정
    analogWrite(motorA_B1, 0);

    Serial.print(data); // 시리얼 모니터에 내가 입력한 값을 화면에 출력
    Serial.println("초 동안 유지"); // 같은 줄에 시리얼 모니터에 "초 동안 유지" 출력

    delay(data * 1000); // 내가 입력한 값에 1000을 곱해 해당 초만큼 모터가 켜지도록 설정

    analogWrite(motorA_A1, 0); // 모터가 돌아간 후 꺼지도록 설정
    analogWrite(motorA_B1, 0);

    Serial.println("종료"); // 시리얼 모니터에 "종료" 출력
  }
  
}
