//---------------------Defines------------------------

#define Pin_R 6
#define Pin_G 11
#define Pin_B 3
#define Pin_T1 13
#define Pin_T2 16
#define Pin_T3 17
#define Pin_T4 19

#define del_fade 10
float brightness_percent = 100; //0%-100%

int white_offset_R = 100;
int white_offset_G = 40;
int white_offset_B = 10;

//--------------------Initialisierung----------------
int PWM_R = 0;
int PWM_G = 0;
int PWM_B = 0;
int brightness = 0;

void setup() 
{
pinMode (Pin_G, OUTPUT);
pinMode (Pin_R, OUTPUT);
pinMode (Pin_B, OUTPUT);
pinMode (Pin_T1, INPUT_PULLUP);
pinMode (Pin_T2, INPUT_PULLUP);
pinMode (Pin_T3, INPUT_PULLUP);
pinMode (Pin_T4, INPUT_PULLUP);

brightness=brightness_percent*2.55;

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

void RGBwhite(int bright)
{
  PWM_R=bright*white_offset_R/100;
  PWM_G=bright*white_offset_G/100;
  PWM_B=bright*white_offset_B/100;
  analogWrite(Pin_R, PWM_R);
  analogWrite(Pin_G, PWM_G);
  analogWrite(Pin_B, PWM_B);
}

void RGBfadein (int delay_f,int r, int g, int b)
//|Delay(gschwindikeit)| Endwert|R|G|B|
{
  int PWM_R = 0;
  int PWM_G = 0;
  int PWM_B = 0;

  int is_r = 0;
  int is_g = 0;
  int is_b = 0;

  while((PWM_R < r)||(PWM_G < g)||(PWM_B < b))
  {
    if(PWM_R < r)
    {
      PWM_R++;
      analogWrite(Pin_R, PWM_R);
    }
    if(PWM_G < g)
    {
      PWM_G++;
      analogWrite(Pin_G, PWM_G);
    }
    if(PWM_B < b)
    {
      PWM_B++;
      analogWrite(Pin_B, PWM_B);
    }
    delay(delay_f);
  }
}

void loop() 
{
RGBfade(10,255);
delay(5000);
RGBwhite(255);
delay(2000);

}
