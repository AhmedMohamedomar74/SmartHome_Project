#include <DHT.h>;
#define DHTPIN 7     // what pin we're connected to                           //defenation
#define DHTTYPE DHT11   // DHT 22  (AM2302)                                    of
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino  dht.
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
int c=0;
byte in1 = 13;
byte in2=4;
byte redPin=11;
byte greenPin=10;
byte bluePin=9;
String mainString;
byte redLed=3;
byte Greenled=5;
byte BlueLed=6;
byte led0=8;
byte led1=12;
byte led2=2;
void setup() {
Serial.begin(9600);
dht.begin();   
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
pinMode(led0,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
 }

void loop() {
  if (Serial.available()>0)
mainString=Serial.readString();
//Serial.println(mainString);
Read (mainString);
  hum = dht.readHumidity();//read of humidity sensor
  temp= dht.readTemperature();//read of of temp
  
motorspeed(hum,temp);    

RGB();}



void motorspeed(float hum,float temp)
{
  if (hum>=85)
  {
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  }
  else if (hum<=85&&temp>=28)
  {    digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);}
  else 
  {digitalWrite(in2,LOW);
  digitalWrite(in1, LOW);}
  }
  




void RGB() {
 //red
  analogWrite(redPin,255);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);
  delay(150);
//green
  analogWrite(redPin,0);
  analogWrite(greenPin,255);
  analogWrite(bluePin,0);
  delay(150);
//blue
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,255);
  delay(150);
//magenta
  analogWrite(redPin,255);
  analogWrite(greenPin,0);
  analogWrite(bluePin,255);
  delay(150);
//yellow
  analogWrite(redPin,255);
  analogWrite(greenPin,255);
  analogWrite(bluePin,0);
  delay(150);
//cyan
  analogWrite(redPin,0);
  analogWrite(greenPin,255);
  analogWrite(bluePin,255);
  delay(150);
//white
  analogWrite(redPin,255);
  analogWrite(greenPin,255);
  analogWrite(bluePin,255);
  delay(150);
}
void Read (String mainString)
{ if (mainString == "on0")
{digitalWrite (led0,HIGH);}
else if (mainString == "off0")
{digitalWrite (led0,LOW);}
else if (mainString == "on1")
{digitalWrite (led1,HIGH);}
else if (mainString == "off1")
{digitalWrite (led1,LOW);}
else if (mainString == "on2")
{digitalWrite (led2,HIGH);}
else if (mainString == "off2")
{digitalWrite (led2,LOW);}
else { byte FirstCommaIndex=mainString.indexOf(',');
    byte SecondCommaIndex=mainString.indexOf(',' ,FirstCommaIndex+1);
    String red=mainString.substring(0,FirstCommaIndex);
    String green=mainString.substring(FirstCommaIndex+1,SecondCommaIndex);
    String blue=mainString.substring(SecondCommaIndex+1);
int r=red.toInt();    
int g=green.toInt();
int b=blue.toInt();
analogWrite(redLed,r);
analogWrite(Greenled,g);
analogWrite(BlueLed,b);}  }  
