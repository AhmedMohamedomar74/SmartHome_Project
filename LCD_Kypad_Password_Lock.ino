/*
 * Circuit Schematic https://goo.gl/VXVMNr
 * https://youtube.com/arafamicrosystems
  The circuit:
 * LCD RS pin to digital pin A0
 * LCD Enable pin to digital pin A1
 * LCD D4 pin to digital pin A2
 * LCD D5 pin to digital pin A3
 * LCD D6 pin to digital pin A4
 * LCD D7 pin to digital pin A5
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 
 */
 

// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>  
Servo myservo;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {6,3,4,2}; 
byte colPins[COLS] = {8, 12, 13};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char StorePass[]="1670";
int i=0,count=0,c=0,number=sizeof(StorePass)-1;
char pass[sizeof(StorePass)-1];
const byte speaker = 5;
const byte lamp=10;
void setup() {
 Serial.begin(9600); // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Enter the Pass");
  lcd.setCursor(0, 1);
 myservo.attach(9);
  pinMode(speaker,OUTPUT);
  myservo.write(0);}

void loop() 
{
  char key = keypad.getKey();
  
  if (key>='0'&&key!='#')
  {
    lcd.print('*');
    pass[i]=key;
    i++;
  }else if(key=='#')
  {
    if(i==number)
    {
      for(int j=0;j<number;j++)
      {
        if(pass[j]==StorePass[j])count++;
      }
      if(count==number)
      {
      correct();
      }else
      {
        wrong();
      }
    }
 
    else
    {
      wrong();
    }
  }
  Serial.println(c);
  if (c==3){
    
alarming();    
  }
    }


void wrong()
{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Wrong Pass     ");
        delay(500);
        i=0;
        count=0;
        lcd.setCursor(0,0);
        lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
        c++;
}
void correct()
{  lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Correct Pass    ");
        lcd.setCursor(0,1);
        lcd.print("wolecome        ");
        myservo.write(90);
        delay(2000);
         lcd.clear();
        i=0;
        count=0;
        myservo.write(0);
        lcd.setCursor(0,0);
        lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
        c=0;
        digitalWrite(lamp,HIGH);}
 
  void alarming()
  {  lcd.clear();
   lcd.print("Stealing");
    digitalWrite(speaker,HIGH);
  digitalWrite(lamp,HIGH);
 delay(1000);
  digitalWrite(speaker,LOW);
    digitalWrite(lamp,LOW);
delay(500);
    digitalWrite(speaker,HIGH);
  digitalWrite(lamp,HIGH);
 delay(1000);
  digitalWrite(speaker,LOW);
    digitalWrite(lamp,LOW);
delay(500);
    digitalWrite(speaker,HIGH);
  digitalWrite(lamp,HIGH);
 delay(1000);
  digitalWrite(speaker,LOW);
    digitalWrite(lamp,LOW);
delay(500);
lcd.clear();
lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
  c=0;}      
