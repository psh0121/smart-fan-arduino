int DCmotor = 11; // 'DC모터'에 11값 입력 (디지털 핀 위치)
int Button = 12; // '푸시버튼'에 12값 입력 (디지털 핀 위치)
int current_state = 0; // '현재 스위치 상태' 변수 선언
int previous_state = 0; // '이전 스위치 상태' 변수 선언
int motor_enabled = 0; // '모터 작동 여부 결정값' 변수 선언

void setup() {
  pinMode(DCmotor,OUTPUT); // DC모터를 출력모드로 설정
  pinMode(Button,INPUT);  // 푸시버튼을 입력모드로 설정
  
  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
}

void loop() {
  current_state = digitalRead(Button); 
  // 버튼에 입력되어진 값을 읽어 현재 스위치 상태 변수에 저장
  
  if((current_state == HIGH) && (previous_state == LOW)){
    // 만약 현재 스위치 상태가 HIGH이면서, 이전 스위치 상태가 LOW인 경우
    
    motor_enabled = 1 - motor_enabled; 
    // 계산한 값을 다시 motor_enabled에 저장
    
    delay(10); // 0.01초 딜레이
  }
  previous_state = current_state; 
  // 현재 스위치 상태 값을 이전 스위치 값에 저장
  
  if(motor_enabled == 1){ // 모터 작동 여부 결정값이 1인 경우
    digitalWrite(DCmotor,LOW); // 모터를 끔
    Serial.println("ON"); // 시리얼 포트에 "ON"출력
  }
  else{
    digitalWrite(DCmotor,HIGH); // 그외에는 모터를 킴
    Serial.println("OFF"); // 시리얼 포트에 "OFF" 출력
  }
}
    
