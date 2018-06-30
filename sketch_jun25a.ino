int led=8;
int button=7;
int flag=0;
float temp;
int state=LOW;
long previousMillis = 0; 
long interval = 3000;           
void setup(){
              Serial.begin(9600);
              pinMode(led,OUTPUT);
              pinMode(button,INPUT);
              
             }
void my_function()
{
   unsigned long currentMillis = millis();
   temp = analogRead(A0);
   if(currentMillis-previousMillis >= interval)
   {
    previousMillis=currentMillis;
    temp =temp * 0.48828125;
    Serial.println(temp);
   }
  int v = digitalRead(button);
  if(v==HIGH && flag==0)
  {
    state = ! state;
    Serial.println(state);
    digitalWrite(led,state);
    flag=1;
     
  }
  else if(v==LOW && flag==1)
  {
    flag=0;
  }
}

void loop(){
   
  my_function();
    }             
