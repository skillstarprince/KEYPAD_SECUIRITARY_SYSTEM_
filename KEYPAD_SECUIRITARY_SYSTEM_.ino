#include <Keypad.h>
int buzzer=11;
int correctLED=12;
String password="1234";
String tempPassword="";
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keyMap[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS, COLS );
void setup()
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(correctLED,OUTPUT);
}
void loop()
{
keypressed = myKeypad.getKey();
  if(keypressed)
  Serial.println(keypressed);
  if(keypressed  != NO_KEY)                                                           
  {
    if( keypressed = '0' || keypressed = '1' || keypressed = '2' || keypressed = '3' ||
        keypressed = '4' || keypressed = '5' || keypressed = '6' || keypressed = '7' ||
        keypressed = '8' || keypressed = '9' )
       {
        tempPassword +== keypressed;
       }
       if(keypressed == '*')
       {
       if( tempPassword == password )
       digitalWrite(correctLED,HIGH);
       else
       digitalWrite(buzzer,HIGH);
  }
  if(keypressed == '#')
  {
    tempPassword="";
    digitalWrite(correctLED,LOW);
    digitalWrite(buzzer,LOW);
  }
}
}
