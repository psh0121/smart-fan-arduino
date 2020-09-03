long previousMillis = 0; // 이전 시간 변수 previousMillis 선언
long interval = 8000; // 시간 간격 변수 interval 선언

int led = 13; // 아두이노 우노에 부착되어 있는 LED 13번 선언

void setup() {
  
  pinMode(led, OUTPUT); // led를 출력모드로 설정
  
  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
}

void loop() {

  unsigned long currentMillis = millis(); // 현재 시간 측정
  
  char c = Serial.read(); //시리얼 정보를 받아 c에 내용 저장
        
  if (c == '1') { // 만약 c가 1이라면
          
    previousMillis = currentMillis; // 이전시간에 현재시간 값을 넣기  
    digitalWrite(led, HIGH); // led가 켜지도록 설정
    Serial.println("불이 켜졌다"); // 시리얼 모니터에 "불이 켜졌다" 출력
  }

  else if (c == '0') { // 만약 c가 0이라면
    digitalWrite(led, LOW); // led가 꺼지도록 설정
    Serial.println("불이 중간에 꺼졌다"); // 시리얼 모니터에 "불이 중간에 꺼졌다" 출력
  }
        
  //만약 현재시간에서 이전 시간을 빼었을때 interval(5000)값보다 크다면
  // = 5초의 시간이 흘렀다면
  if (currentMillis - previousMillis > interval){ 
    digitalWrite(led, LOW); // led가 꺼지도록 설정
    Serial.println("불이 꺼졌다"); // 시리얼 모니터에 "불이 꺼졌다" 출력
  }
}
