//---------------------Defines------------------------

#define Pin_R 6
#define Pin_G 11
#define Pin_B 3

#define del_fade 100
#define brightness 20 //0-255

int PWM = 0;
int PWM_R = 0;
int PWM_G = 0;
int PWM_B = 0;

void setup() 
{
pinMode (Pin_G, OUTPUT);
pinMode (Pin_R, OUTPUT);
pinMode (Pin_B, OUTPUT);

}

void RGBset(int r, int g, int b)
{
  analogWrite(Pin_R, r);
  analogWrite(Pin_G, g);
  analogWrite(Pin_B, b);
}

void RGBfade(int delay_f, int bright)// |Delay| |Brightness|
{
  PWM_R = bright;
  PWM_G = 0;
  PWM_B = 0;
  analogWrite(Pin_R, PWM_R);
  analogWrite(Pin_G, PWM_G);
  analogWrite(Pin_B, PWM_B);

  for(int a=0; a<bright; a++){
    analogWrite(Pin_R, PWM_R);
    analogWrite(Pin_G, PWM_G);
    analogWrite(Pin_B, PWM_B);
    PWM_R =PWM_R-1;
    PWM_G =PWM_G+1;
    delay(delay_f);
  }
  for(int a=0; a<bright; a++){
    analogWrite(Pin_R, PWM_R);
    analogWrite(Pin_G, PWM_G);
    analogWrite(Pin_B, PWM_B);
    PWM_G =PWM_G-1;
    PWM_B =PWM_B+1;
    delay(delay_f);
  }
  for(int a=0; a<bright; a++){
    analogWrite(Pin_R, PWM_R);
    analogWrite(Pin_G, PWM_G);
    analogWrite(Pin_B, PWM_B);
    PWM_B =PWM_B-1;
    PWM_R =PWM_R+1;
    delay(delay_f);
  }
}

void loop() 
{
RGBfade(del_fade, brightness);
delay(1000);
RGBset(brightness,0,0);
delay(1000);
RGBset(0,brightness,0);
delay(1000);
RGBset(0,0,brightness);
delay(1000);
}
