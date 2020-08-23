long int data; //count down timer data

int motorA_A1 = 10;
int motorA_B1 = 9;

void setup() {

  pinMode(motorA_A1, OUTPUT);
  pinMode(motorA_B1, OUTPUT);

  analogWrite(motorA_A1, 0);
  analogWrite(motorA_B1, 0);

  Serial.begin(9600);
}

void loop() {

  while(Serial.available() == 0);

  if(Serial.available() > 0) {

    data = Serial.parseInt();
  }

  if(data > 0) {
    
    analogWrite(motorA_A1, 200);
    analogWrite(motorA_B1, 0);

    Serial.print(data);
    Serial.println("초 동안 유지");

    delay(data * 1000);

    analogWrite(motorA_A1, 0);
    analogWrite(motorA_B1, 0);

    Serial.println("종료");
  }
  
}
