long previousMillis = 0; 
// Interval을 5초로 지정
long interval = 5000; 

int led = 13;
int sw = 5;

void setup() {
        pinMode(led, OUTPUT);
        pinMode(sw, INPUT_PULLUP);
        Serial.begin(9600);
}

void loop() {
        // 현재 시간 측정
        unsigned long currentMillis = millis(); 
        // 시리얼 입력값을 읽는다.
        char c = Serial.read(); 
        
        if (digitalRead(sw) == LOW) {
                previousMillis = currentMillis;  
                digitalWrite(led, HIGH);
        }
        else {
                // a라는 글자를 입력한 경우 Hello문구 출력
                if (c == 'a') { 
                Serial.println("Hello");
                }
        }
        
        // LED가 켜진지 5초뒤에 LED를 끈다
        if (currentMillis - previousMillis > interval){ 
                digitalWrite(led, LOW);
        }
}
