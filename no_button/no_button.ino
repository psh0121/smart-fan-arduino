int DCmotor = 3;  // 아날로그 출력이 가능한 디지털핀 3번에 꽂아줌

void setup() 
{ 
     pinMode(DCmotor, OUTPUT); // 변수 선언후 DC모터 핀모드를 출력모드로 설정
} 


void loop()
{ 
  analogWrite(DCmotor, HIGH); // DC모터가 돌아가도록 설정
}
