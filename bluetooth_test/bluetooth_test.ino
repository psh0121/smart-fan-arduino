#include <SoftwareSerial.h> //블루투스 시리얼 통신 라이브러리 추가

SoftwareSerial bluetooth(5,6); //블루투스 설정 블루투스(Tx, Rx)

void setup() {
  Serial.begin(9600); // 시리얼 통신을 위한 보드레이트 설정
  bluetooth.begin(9600); // 블루투스 통신 시작
}

void loop() {
  if (bluetooth.available()) { //블루투스에 값이 들어오면
    Serial.write(bluetooth.read()); //시리얼에 입력된 데이터를 블루투스로 읽어옴
  }
  if (Serial.available()) { //시리얼에 값이 들어오면
    bluetooth.write(Serial.read()); //블루투스에서 받은 데이터를 시리얼에서 읽어옴
  }
}
