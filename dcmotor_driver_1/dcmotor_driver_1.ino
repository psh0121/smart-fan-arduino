int in1 = 7; // in1을 7번포트에 연결
int in2 = 5; // in2를 5번 포트에 연결

void setup() {
  
  pinMode(in1, OUTPUT); // in1을 출력모드로 설정
  pinMode(in2, OUTPUT); // in2를 출력모드로 설정
  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정 
}

void loop() {
  
  if(Serial.available()) { // 만약 시리얼 모니터에 데이터가 들어왔을 경우
    
    char in_data; // 데이터가 들어온 값을 저장할 변수 in_data
    in_data = Serial.read(); // 시리얼 모니터에 값이 입력되면 그 값을 in_data에 입력
    
    if(in_data == '1') { // 만약 in_data가 1일 경우 (정방향)
      
      digitalWrite(in1, HIGH); // in1을 HIGH로 설정
      digitalWrite(in2, LOW); // in2를 LOW로 설정
    }
    
    else if(in_data == '2') { // 만약 in_data가 2일 경우 (반대방향)
      
      digitalWrite(in1, LOW); // in1을 LOW로 설정
      digitalWrite(in2, HIGH); // in2를 HIGH로 설정
    }
    
    else { // 시리얼 모니터에 데이터가 들어오지 않았을 경우 (정지)
      
      digitalWrite(in1, LOW); // in1을 LOW로 설정
      digitalWrite(in2, LOW); // in2를 LOW로 설정
    }
  }

}
