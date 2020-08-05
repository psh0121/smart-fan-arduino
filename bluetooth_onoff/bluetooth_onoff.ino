#include <SoftwareSerial.h>
SoftwareSerial BT(3, 2);

byte DCmotor = 11;

char DataBluetooth = ' ';
 
 
void setup()
{
   
Serial.begin(9600);
BT.begin(9600);
Serial.println("");
Serial.println("Inciando Control ...");

pinMode (DCmotor, OUTPUT);

analogWrite(DCmotor, LOW);

}
 
void loop()
{
  
 if(BT.available()) 
{
  DataBluetooth = BT.read();
  Serial.print(DataBluetooth);

  if(DataBluetooth == 'I')
  {
    analogWrite(DCmotor, LOW);
    BT.println("i");
    Serial.println("");
  }

  if(DataBluetooth == 'A')
  {
    analogWrite(DCmotor, LOW);
    BT.println("a");
    Serial.println("");
  }

  if(DataBluetooth == 'D')
  {
    analogWrite(DCmotor, HIGH);
    BT.println("d");
    Serial.println("");
  }

  if(DataBluetooth == 'R')
  {
    analogWrite(DCmotor, LOW);
    BT.println("r");
    Serial.println("");
  }

  if(DataBluetooth == 'S')
  {
    analogWrite(DCmotor, LOW);
    BT.println("s");
    Serial.println("");
  }
}
}
