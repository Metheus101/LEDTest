//---------------------Defines------------------------

#define Pin_R 6
#define Pin_G 11
#define Pin_B 3

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
  float r=bright*white_offset_R/100;
  float g=bright*white_offset_G/100;
  float b=bright*white_offset_B/100;
  analogWrite(Pin_R, r);
  analogWrite(Pin_G, g);
  analogWrite(Pin_B, b);
}

void RGBfadein (int delay_f,int r, int g, int b)
//|Delay(gschwindikeit)| Endwert|R|G|B|
{
  int set_r = 0;
  int set_g = 0;
  int set_b = 0;

  int is_r = 0;
  int is_g = 0;
  int is_b = 0;

  while((set_r < r)||(set_g < g)||(set_b < b))
  {
    set_r++;
    set_g++;
    set_b++;
    
    if(set_r < r)
    {
      analogWrite(Pin_R, set_r);
    }
    if(set_g < g)
    {
      analogWrite(Pin_G, set_g);
    }
    if(set_b < b)
    {
      analogWrite(Pin_B, set_b);
    }
    delay(delay_f);
  }
}

void loop() 
{
RGBfadein(10,255,0,10);
RGBset(0,0,0);
delay(1000);

}
