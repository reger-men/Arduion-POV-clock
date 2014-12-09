  // defining the alphabet
  #include "font.h"
  #include <Time.h>
  
  // define the Arduino LED pins in use
  const int LEDpins[] = {9,8,7,6,5,4,3,2};
  int rows= 8;		        // Total LED's in a row
  // number of LEDs
   const int charHeight = 8;
   const int charWidth = 5;
  
  
  
  // sensor setup
  const int sensorPIN = 10;  // define the Arduino sensor pin
  int sensVal;  // variable to store the value coming from the sensor
  int i;
  char textString[] = "Your Text";
  String tmp_str;
  
  void setup()
  {
    setTime(00,00,00,30,12,2014);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, INPUT);
    for (i = 0; i < rows; i++)
      pinMode(LEDpins[i], OUTPUT);    
  }
  
  void loop()
  {
    tmp_str=clock();
    tmp_str=tmp_str+" ";
    while(digitalRead(sensorPIN) != 0)
    {
     digitalWrite(13, LOW);   // set the LED off
    }
    digitalWrite(13, HIGH);   // set the LED on
    // printen clock letter
    for (int k=0; k<tmp_str.length(); k++){
      printLetter(tmp_str.charAt(k));
      }
    delay(2);
    for (int k=sizeof(textString)-1; k>-1; k--){
      printLetterboven(textString[k]);;
      }  
  }
  
  String clock(){
    String result;
    String str1;
    String str2;
    String str3;
    if (hour() < 10)
      str1 = "0"+String(hour());
    else
      str1 = String(hour());
    if (minute() < 10)
      str2 = "0"+String(minute());
    else
      str2 = String(minute());
    if (second() < 10)
      str3 = "0"+String(second());
    else
      str3 = String(second());
    result = str1+":"+str2+":"+str3;
    return result;
  }
  
void printLetterboven(char ch)
  {
    // make sure the character is within the alphabet bounds (defined by the font.h file)
    // if it's not, make it a blank character
    if (ch < 32 || ch > 126){
      ch = 32;
      }
    // subtract the space character (converts the ASCII number to the font index number)
    ch -= 32;
    // step through each byte of the character array
    for (int i=charWidth-1; i>-1; i--) {
      byte b = font[ch][i];
      for (int j=0; j<charHeight; j++) {
        digitalWrite(LEDpins[j], bitRead(b,j));
        }
      delay(1);
      }
    //clear the LEDs
    for (i = 0; i < rows; i++)
      digitalWrite(LEDpins[i] , LOW);
    // space between letters
    delay(1);
  
  }  
  
  void printLetter(char ch)
  {
    // make sure the character is within the alphabet bounds (defined by the font.h file)
    // if it's not, make it a blank character
    if (ch < 32 || ch > 126){
      ch = 32;
      }
    // subtract the space character (converts the ASCII number to the font index number)
    ch -= 32;
    // step through each byte of the character array
    for (int i=0; i<charWidth; i++) {
      byte b = font[ch][i];
      
      for (int j=0; j<charHeight; j++) {
        digitalWrite(LEDpins[j], bitRead(b, 7-j));
        }
      delay(1);
      }
    //clear the LEDs
    for (i = 0; i < rows; i++)
      digitalWrite(LEDpins[i] , LOW);
    // space between letters
    delay(1);
  
  }
