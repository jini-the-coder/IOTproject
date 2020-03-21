String voice;
int led1 = 8;
int led2 = 11;
int led3 = 13; //Connect 1ST TRANSISTOR COLLECTOR To Pin #13

int motorPin1 = 3; // pin 2 on L293D IC
int motorPin2 = 4; // pin 7 on L293D IC
int tv = 6; //Connect 1ST TRANSISTOR COLLECTOR To Pin #12
 
void allon(){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(tv, HIGH);
     digitalWrite(motorPin1, LOW); 
     digitalWrite(motorPin2, HIGH); 
}
void alloff(){
     digitalWrite(led1, LOW);   
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW);   
     digitalWrite(tv, LOW);
     digitalWrite(motorPin1, LOW); 
     digitalWrite(motorPin2, LOW);
}
 
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(tv, OUTPUT);
}
 
void loop() {
   while (Serial.available()){ 
   delay(10);
  char c = Serial.read(); 
  if (c == '#') {
    break;
    }
  voice += c; 
   }
  if (voice.length() > 0) {
  Serial.println(voice);
   
if(voice == "all on" || voice == "alldeviceson") {
  allon();
  }  
else if(voice == "all off" || voice =="i love" || voice == "alldevicesoff" || voice == "all of"){
  alloff();
  } 
else  if(voice == "led on" || voice == "LED on" || voice == "lon") {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  }
else if(voice == "fan on" || voice == "fon") {
   digitalWrite(motorPin1, LOW);
   digitalWrite(motorPin2, HIGH); 
  }
  else if(voice == "TV on" || voice =="tv on" || voice =="bb on" || voice =="ton") {
    digitalWrite(tv, HIGH);
    }
 
else if(voice == "led off" || voice == "led of" || voice == "LED off" || voice=="loff") {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  }
else if(voice == "fan off" || voice =="son of" || voice =="foff")  {
  digitalWrite(motorPin1, LOW); 
  digitalWrite(motorPin2, LOW); 
   }
else if(voice == "TV off" || voice =="tv off" || voice =="bb off" || voice=="toff") {
  digitalWrite(tv, LOW);
  }   
voice="";}}
