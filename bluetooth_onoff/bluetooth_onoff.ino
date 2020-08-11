#include <SoftwareSerial.h> //블루투스 시리얼 통신 라이브러리 추가

SoftwareSerial BT(3, 2); //블루투스 설정 bluetooth(Tx, Rx)

byte DCmotor = 11; //DC모터 디지털 11번 핀에 연결

char DataBluetooth = ' '; //블루투스를 통해 입력되어진 값 저장
 
 
void setup(){
  
  Serial.begin(9600); //시리얼 통신을 위한 보드레이트 설정
  BT.begin(9600); //블루투스 통신 시작
  
  Serial.println(""); //시리얼 모니터에 내용 출력
  Serial.println("Inciando Control ...");

  pinMode (DCmotor, OUTPUT); //DC모터 출력모드로 설정
  analogWrite(DCmotor, LOW); //시작할때 DC모터가 꺼져있는 상태가 되어있도록 설정
}
 
void loop() {
  
  if(BT.available()) //만약 블루투스가 연결되었다면
  {
    DataBluetooth = BT.read(); //블루투스 통신을 통해 데이터를 읽어 DataBluetooth로 값 입력
    Serial.print(DataBluetooth); //시리얼 모니터에 DataBluetooth 출력

    if(DataBluetooth == 'I') //만약 블루투스 통신을 통해 입력된 값이 'I'라면
    {
      analogWrite(DCmotor, LOW); //DC모터가 꺼지도록 설정
      BT.println("i"); //출력
      Serial.println("");
    }

    if(DataBluetooth == 'A') //만약 블루투스 통신을 통해 입력된 값이 'A'라면
    {
      analogWrite(DCmotor, LOW); //DC모터가 꺼지도록 설정
      BT.println("a"); //출력
      Serial.println("");
    }

    if(DataBluetooth == 'D') //만약 블루투스 통신을 통해 입력된 값이 'D'라면
    {
      analogWrite(DCmotor, HIGH); //DC모터가 켜지도록 설정
      BT.println("d"); //출력
      Serial.println("");
    }

    if(DataBluetooth == 'R') //만약 블루투스 통신을 통해 입력된 값이 'R'라면
    {
      analogWrite(DCmotor, LOW); //DC모터가 꺼지도록 설정
      BT.println("r"); //출력
      Serial.println("");
    }

    if(DataBluetooth == 'S') //만약 블루투스 통신을 통해 입력된 값이 'S'라면
    {
      analogWrite(DCmotor, LOW); //DC모터가 꺼지도록 설정
      BT.println("s"); //출력
      Serial.println("");
    }
  }
}
