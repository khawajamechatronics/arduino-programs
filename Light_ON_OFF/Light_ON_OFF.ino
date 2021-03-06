#define trigPin1 3
#define echoPin1 2
#define trigPin2 5
#define echoPin2 4

#define led1 11
#define led2 7

long duration1=0,distance1=0;
long duration2=0,distance2=0;
int count1=0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(12,OUTPUT);
}
int sensor1()
{
digitalWrite(trigPin1, LOW);
delayMicroseconds(100);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(100);
digitalWrite(trigPin1, LOW);
duration1=pulseIn(echoPin1,HIGH);
distance1=(duration1/2)/29.1;

if(distance1<60)
digitalWrite(led1, HIGH);
else
digitalWrite(led1, LOW);
return(distance1);
}

int sensor2()
{
digitalWrite(trigPin1, LOW);
delayMicroseconds(100);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(100);
digitalWrite(trigPin2, LOW);
duration2=pulseIn(echoPin2,HIGH);
distance2=(duration2/2)/29.1;

if(distance2<100)
digitalWrite(led2, HIGH);
else
digitalWrite(led2, LOW);
return(distance2);
}

void loop() {
  
//int temp=0;
sensor1();
sensor2();
if((distance1<60) && (distance2>100))
{
 do
 {
   delay(150);
   sensor1();
   sensor2();
    if((distance1>60) && (distance2>100))
    break;
 }
 while(!((distance1>60) && (distance2<100))); // True or false logic, T&F=T; F&T=T

 if((distance1>60) && (distance2<100))
 {
   do
   {
     delay(100);
     sensor1();
     sensor2();
   
   }
   while(!(distance1>60 && distance2>100));
   if(distance1>60 && distance2>100)
   {
     count1++;
     Serial.println(count1);
   }
 }
}
sensor1();
sensor2();


//------OUT-------
if((distance1>60) && (distance2<100))
{
 do
 {
   delay(200);
   sensor1();
   sensor2();
    //if((distance1>60) && (distance2>100))
    //break;
 }
 while(!((distance1<60) && (distance2<100))); // True or false logic, T&F=T; F&T=T

 if((distance1<60)&&(distance2<100))
 {
   do
   {
     delay(200);
     sensor1();
     sensor2();
     //if((distance1>60) && (distance2<100))
     //break;
   }
    while(!((distance1>60) && (distance2>100)));
    
    if(distance1>60 && distance2>100)
   {
     count1--;
     if(count1<0)
     count1=0;
     
     Serial.println(count1);
   }
 }
}
if(count1>=1)
digitalWrite(12,LOW);
else
digitalWrite(12,HIGH);

delay(10);
}
