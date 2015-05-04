
  const int buttonPin = 2;     
  const int ledPin =  13;      
  int buttonState = 0;   
  int printOnce = 1;
  int buttonClick = 0;
  int lastState = LOW;
  int time,timebegin,timeend;


 void setup() {
    pinMode(ledPin, OUTPUT);
    randomSeed(analogRead(0));
    pinMode(buttonPin, INPUT);
    attachInterrupt(0, blink, HIGH);  
     
    Serial.begin(9600);
    Serial.println(timebegin); 

 }

 void loop(){
    buttonState = digitalRead(buttonPin);
    if (buttonClick == 2) {
        digitalWrite(ledPin, LOW);
        time = timeend-timebegin;
          if(printOnce == 1){
            lastState = HIGH;
            Serial.print("Czas: ");
            Serial.println(time); 
            printOnce++;
          }
    }
    if(buttonState == LOW && lastState==HIGH){
       lastState = LOW;
       delay(random(3000)+1000);
       digitalWrite(ledPin, HIGH);
       timebegin = millis();
       printOnce = 1;
       buttonClick = 1;
    }
 } 
 void blink(){
    buttonClick = 2;
    timeend = millis();
 }
