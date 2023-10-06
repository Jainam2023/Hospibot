#include<Servo.h>
Servo s1;
int rv=400,lv=400,ldrv=;
int rs,ls,ldr;
double dist,dur,dv;
void setup() {
  s1.attach(9);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(5,0);
  pinMode(6,OUTPUT);
  digitalWrite(6,0);
  pinMode(7,OUTPUT);
  digitalWrite(7,1);
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
}

void loop() {
  rs=analogRead(A2);
  ls=analogRead(A3);
  ldr=analogRead(A1);
  digitalWrite(11,1);
  delayMicroseconds(5);
  digitalWrite(11,0);
  dur=pulseIn(10,1);
  dist=0.017*dur;
  if(ldr<ldrv)
  {
    s1.write(90);
    if(dist<dv)
  {
   digitalWrite(6,1);
   halt();
   digitalWrite(5,1); 
  }
  else
  {
    digitalWrite(6,0);
   digitalWrite(5,0); 
    if(rs>rv && ls>lv)
  {
    fwd();
  }
  if(rs>rv && ls<lv)
  {
    left();
  }
  if(rs<rv && ls>lv)
  {
    right();
  }
  }
  }
  else()
  {
    digitalWrite(6,1);
    halt();
    for(int i=90;i<=180;i++)
    {
      s1.write(i);
      delay(10);
    }
    fwd();
  }
  
}
fwd()
{
  digitalWrite(1,1);
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,1);  
}
back()
{
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,0);  
}
left()
{
  digitalWrite(1,1);
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,0);  
}
right()
{
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(3,0);
  digitalWrite(4,1);  
}
halt()
{
 digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);   
}
