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
int CurrBtn;
int LastBtn;
unsigned long LastPressTime;
int score=0;
int now;
int last;
int first_Pressed_Led;
int second_Pressed_Led;
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

LastPressTime=millis();

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
}

void loop() {
  // put your main code here, to run repeatedly:

for(int i=0;i<NUM_OF_LEDS;i++){
CurrBtn=digitalRead(Btns[i]);
if((CurrBtn==LOW)&&(LastBtn==HIGH)&&(millis()-LastPressTime>50)){
  LastPressTime=millis();
  now=i;
  if(i==rnd){
    digitalWrite(RedLed,HIGH);
    tone(buzzerPin, 400, 300);
    delay(500);
    digitalWrite(RedLed,LOW);
    score=4;
  } else {
    if(last!=now){
    delay(200);
    last=i;
    } else if(last==now && score!=4){
      digitalWrite(BlueLed,HIGH);
      digitalWrite(YellowLed,HIGH);
      tone(buzzerPin, 650);
      delay(200);
      tone(buzzerPin, 450, 200);
      delay(300);
      digitalWrite(BlueLed,LOW);
      digitalWrite(YellowLed,LOW);
    }
    if(score==0){
    first_Pressed_Led=i;
    score++;
    Serial.println(score);
  }
    if(score==1){
      if(i!=first_Pressed_Led){
        second_Pressed_Led=i;
        score++;
        Serial.println(score);
      }
    }
    if(score==2){
      if(i!=first_Pressed_Led && i!=second_Pressed_Led){
        score++;
        Serial.println(score);
      }
    }
    if(score==4){
      score++;
      Serial.println(score);
    }
  }

  if(score==3){
    Win();
    score=4;
  }
  if(score==4){
  for(int i=0;i<NUM_OF_LEDS;i++){
    digitalWrite(Leds[i],LOW);
  }
}
}
LastBtn=CurrBtn;
}

if(score==5){
  score=0;
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
}
}

void Win(){
  digitalWrite(GreenLed,HIGH);
  tone(buzzerPin, 784,300);
  delay(500);
  digitalWrite(GreenLed,LOW);
}