//---------------------Defines------------------------

#define Pin_R 6
#define Pin_G 11
#define Pin_B 3

#define PWM_R 30
#define PWM_G 100
#define PWM_B 100

#define Speed 10

int PWM = 0;

void setup() {
pinMode (Pin_G, OUTPUT);
pinMode (Pin_R, OUTPUT);
pinMode (3, OUTPUT);
}

void loop() {
PWM=0;
analogWrite(Pin_R,0);
analogWrite(Pin_G,0);
analogWrite(Pin_B,0);
for(int a=0; a<255; a++)
{
analogWrite(Pin_R,PWM);

PWM++;
delay (Speed);
}
for(int a=0; a<255; a++)
{
analogWrite(Pin_R,PWM);

PWM--;
delay (Speed);
}
analogWrite(Pin_R,0);
analogWrite(Pin_G,0);
analogWrite(Pin_B,0);
for(int a=0; a<255; a++)
{

analogWrite(Pin_G,PWM);

PWM++;
delay (Speed);
}
for(int a=0; a<255; a++)
{

analogWrite(Pin_G,PWM);

PWM--;
delay (Speed);
}
analogWrite(Pin_R,0);
analogWrite(Pin_G,0);
analogWrite(Pin_B,0);
for(int a=0; a<255; a++)
{
analogWrite(Pin_B,PWM);
PWM++;
delay (Speed);
}
for(int a=0; a<255; a++)
{

analogWrite(Pin_B,PWM);
PWM--;
delay (Speed);
}
analogWrite(Pin_R,0);
analogWrite(Pin_G,0);
analogWrite(Pin_B,0);
for(int a=0; a<255; a++)
{
analogWrite(Pin_R,PWM);
analogWrite(Pin_G,PWM);
analogWrite(Pin_B,PWM);
PWM++;
delay (Speed);
}
for(int a=0; a<255; a++)
{
analogWrite(Pin_R,PWM);
analogWrite(Pin_G,PWM);
analogWrite(Pin_B,PWM);
PWM--;
delay (Speed);
}
}
