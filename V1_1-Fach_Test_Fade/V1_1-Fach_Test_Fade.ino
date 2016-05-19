//---------------------Defines------------------------

#define Pin_R 6
#define Pin_G 11
#define Pin_B 3

#define Speed 100
#define Brightness 10 //0-255

int PWM = 0;
int PWM_R = Brightness;
int PWM_G = 0;
int PWM_B = 0;

void setup() {
pinMode (Pin_G, OUTPUT);
pinMode (Pin_R, OUTPUT);
pinMode (Pin_B, OUTPUT);

analogWrite(Pin_R, Brightness);
analogWrite(Pin_G,0);
analogWrite(Pin_B,0);
}

void loop() {
  for(int a=0; a<Brightness; a++){
    analogWrite(Pin_R, PWM_R);
    analogWrite(Pin_G, PWM_G);
    analogWrite(Pin_B, PWM_B);
    PWM_R =PWM_R-1;
    PWM_G =PWM_G+1;
    delay(Speed);
  }
  for(int a=0; a<Brightness; a++){
    analogWrite(Pin_R, PWM_R);
    analogWrite(Pin_G, PWM_G);
    analogWrite(Pin_B, PWM_B);
    PWM_G =PWM_G-1;
    PWM_B =PWM_B+1;
    delay(Speed);
  }
  for(int a=0; a<Brightness; a++){
    analogWrite(Pin_R, PWM_R);
    analogWrite(Pin_G, PWM_G);
    analogWrite(Pin_B, PWM_B);
    PWM_B =PWM_B-1;
    PWM_R =PWM_R+1;
    delay(Speed);
  }
}
