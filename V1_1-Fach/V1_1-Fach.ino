//---------------------Defines------------------------

#define Pin_R 6
#define Pin_G 11
#define Pin_B 3

#define del_fade 100
#define brightness 100 //0-255

int PWM = 0;
int PWM_R = 0;
int PWM_G = 0;
int PWM_B = 0;

void setup() {
pinMode (Pin_G, OUTPUT);
pinMode (Pin_R, OUTPUT);
pinMode (Pin_B, OUTPUT);

}

void fadeRGB(int delay_f, int bright){
  
  analogWrite(Pin_R, bright);
  analogWrite(Pin_G,0);
  analogWrite(Pin_B,0);

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

void loop() {
fadeRGB(del_fade, brightness);
}
