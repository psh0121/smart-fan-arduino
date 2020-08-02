const int DCmotor = 11; // 'DC'모터에 11값 입력 (디지털 핀 위치)
const int  Button = 12; // '푸시버튼'에 12값 입력 (디지털 핀 위치)

int button_push_counter = 0; // '버튼 누름 횟수' 변수 선언   
int current_button_state = 0; // '현재 스위치 스위치 상태' 변수 선언         
int previous_button_state = 0; // '이전 스위치 상태' 변수 선언

void setup() {
  pinMode(DCmotor, OUTPUT); // DC모터를 출력모드로 설정
  pinMode(Button, INPUT); // 푸시버튼을 입력모드로 설정
  
  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
}

void loop() {
  current_button_state = digitalRead(Button);
  // 버튼에 입력 되어진 값을 읽어 현재 스위치 상태 변수에 저장

  if (current_button_state != previous_button_state) {
    // 만약 현재 스위치 상태 값과 이전의 스위치 상태 값이 다를 경우
    
    if (current_button_state == HIGH) { // 만약 버튼이 눌렸을 경우
      button_push_counter++; // 버튼 누름 횟수를 +1 증가
    } 
    else {
    }
    delay(50); // 0.05초 딜레이
  }
  previous_button_state = current_button_state;
  // 현재 스위치 상태 값을 이전 스위치 값에 저장
  
  if (button_push_counter %4 == 1) {
    // 버튼 누름 횟수를 4으로 나눈 나머지가 1일 경우
    
    analogWrite(DCmotor, 110); 
    // DC모터가 약하게 돌아가도록 설정 (값이 커질수록 약해짐)
    Serial.println("weak wind"); // 시리얼 포트에 "weak wind" 출력
  }
  else if(button_push_counter %4 == 2) {
    // 버틈 누름 횟수를 4으로 나눈 나머지가 2일 경우
    
    analogWrite(DCmotor, 50); // DC모터가 중간세기로 돌아가도록 설정
    Serial.println("middle wind"); // 시리얼 포트에 "middle wind" 출력
  }
    else if(button_push_counter %4 == 3) {
    // 버틈 누름 횟수를 4으로 나눈 나머지가 3일 경우
    
    analogWrite(DCmotor, LOW); // DC모터가 강하게 돌아가도록 설정
    Serial.println("strong wind"); // 시리얼 포트에 "strong wind" 출력
  }
  else {
    digitalWrite(DCmotor, HIGH); // 그외에는 DC모터를 끔
    Serial.println("stop"); // 시리얼 포트에 "stop" 출력
  }  
}
