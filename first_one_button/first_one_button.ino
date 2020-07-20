int state = 0; // 버튼의 누름 여부를 파악하기 위한 변수 선언

void setup() {
  
  pinMode (12, INPUT); // 12번핀은 버튼의 입력모드로 설정
  pinMode (13, OUTPUT); // 13번핀은 DC모터의 출력모드로 설정
  
}

void loop() {
  
  if(digitalRead(12) == HIGH) { // 버튼이 눌렸을 때
    
    if(state == 0) { // state의 값이 0이라면
      
      state = 1; // state에 값 1을 넣어줌
      
    }
    
    else if(state == 1) { // state의 값이 1이라면
      
      state = 0; // state에 값 0을 넣어줌
      
    }
  }
  
  if(state == 1) { // state가 1이라면
    
    digitalWrite(13, HIGH); // DC모터를 돌림
    
  }
  
  else if (state == 0) { // state가 0이라면
    
    digitalWrite(13, LOW); // DC모터를 끔
    
  }
}
