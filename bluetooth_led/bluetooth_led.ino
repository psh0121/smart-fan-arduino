#include <SoftwareSerial.h> //블루투스 시리얼 통신 라이브러리 추가

SoftwareSerial Blue(5, 6); //블루투스 설정 블루투스(Tx, Rx)

long int data; // '불빛' 변수 값의 데이터
 
int LED = 13; // 'LED' 변수 선언
long int password1 = 92; // '불이 켜질때'의 변수값 선언
long int password2 = 79; // '불이 꺼질때'의 변수값 선언
 
char state = 0; 
 
 
void setup()
{
   
pinMode(LED, OUTPUT); // LED를 출력모드로 설정
digitalWrite(LED, LOW); // 불빛이 꺼짐

Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
Blue.begin(9600); // 블루투스 통신 시작
 
}
 
void loop()
{
  while(Blue.available()==0); // 블루투스에 값이 '0'일동안 반복
 
 if(Blue.available()>0) { // 블루투스에 값이 들어오면
  data = Blue.parseInt(); // 블루투스값을 'data'에 입력
 } 
 
delay(400); // 0.4초 딜레이

if (data == password1) { // 만약 데이터값과 불이 켜질때의 값이 같다면
  digitalWrite(LED,HIGH); // LED 불빛을 최대로 설정
  Serial.println("LED ON "); // 시리얼 포트에 "LED ON" 출력
  }
   
   if( data == password2) { // 만약 데이터값과 불이 꺼질때의 값이 같다면
    digitalWrite(LED,LOW); // LED 불빛은 최하로 설정
    Serial.println("LED OFF"); // 시리얼 포트에 "LED OFF" 출력
   }
 }
