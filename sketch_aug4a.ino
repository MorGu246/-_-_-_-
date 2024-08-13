#define RedLed 2
#define YellowLed 3
#define GreenLed 4
#define BlueLed 12
#define RedBtn 5
#define YellowBtn 6
#define GreenBtn 7
#define BlueBtn 8
#define buzzerPin 10
#define NUM_OF_LEDS 4
int Leds[NUM_OF_LEDS]={RedLed,YellowLed,GreenLed,BlueLed};
int Btns[NUM_OF_LEDS]={RedBtn,YellowBtn,GreenBtn,BlueBtn};
int rnd;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
randomSeed(analogRead(A1));
for(int i=0;i<NUM_OF_LEDS;i++){
  pinMode(Leds[i],OUTPUT);
}
for(int i=0;i<NUM_OF_LEDS;i++){
  pinMode(Btns[i],INPUT_PULLUP);
}


rnd=random(0,NUM_OF_LEDS);
for(int i=0;i<NUM_OF_LEDS;i++){
  if(i==rnd){
    digitalWrite(Leds[i],LOW);
  } else{
    digitalWrite(Leds[i],HIGH);
  }
}
delay(1000);
for(int i=0;i<NUM_OF_LEDS;i++){
 digitalWrite(Leds[i],LOW); 
}
delay(500);
tone(buzzerPin, 500, 300);
delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:

for(int i=0;i<NUM_OF_LEDS;i++){
  if(digitalRead(Btns[rnd])==LOW){
    digitalWrite(RedLed,HIGH);
  } else {
    digitalWrite(RedLed,LOW);
  }
}
}