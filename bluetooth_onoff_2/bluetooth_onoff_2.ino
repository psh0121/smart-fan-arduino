#include <SoftwareSerial.h>

SoftwareSerial Blue(5,6);

long int data;

int DCmotor = 11;
long int password1 = 92;
long int password2 = 79;

char state = 0;

void setup()
{

  pinMode(DCmotor, OUTPUT);
  analogWrite(DCmotor, LOW);

  Serial.begin(9600);
  Blue.begin(9600);
  
}

void loop()
{

  while(Blue.available()==0);

  if(Blue.available()>0) {
    data = Blue.parseInt();
  }

  delay(400);

  if (data == password1) {
    analogWrite(DCmotor, 250);
    Serial.println("DCmotor ON");
  }

  if (data == password2) {
    analogWrite(DCmotor, 0);
    Serial.println("DCmotor OFF");
  }
}
