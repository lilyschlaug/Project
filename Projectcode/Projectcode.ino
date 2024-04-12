// include the library code:
#include <Wire.h>               //For I2C
#include <LiquidCrystal_I2C.h>  //For I2C LCD
// used example code at this link  http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//pin that the buttons are connected to
int button4 = 2;                    
int button8 = 3; 
int button12 = 4; 

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display


void setup() {
  //set the button pin as an input
  pinMode(button4, INPUT_PULLUP);     
  pinMode(button8, INPUT_PULLUP);  
  pinMode(button12, INPUT_PULLUP);    
  
  // set up the LCD's number of columns and rows:
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight
}

void loop() {
  /*This block tests the LCD It worked with my setup SCL and SDA are
    supposed to be connected to A5 and A4 respectively.*/
  lcd.setCursor(3, 0); // set the cursor to column 3, line 0
  lcd.print("SunFounder"); // Print a message to the LCD
  lcd.setCursor(2, 1); // set the cursor to column 2, line 1
  lcd.print("Hello, World!"); // Print a message to the LCD.

  /*Your code starts here*/

  //display info to user, max 32 characters, 16x2 display
  //clear display
  lcd.clear();
  // Print a message to the LCD.
  lcd.print("Arnold Palmer");
  // set the cursor to column 0, line 1 (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the oz options 
  lcd.print("4oz, 8oz, 12oz");

  //user input 4, 8, or 12 oz via buttons
  //solenoids open for time based on oz. requested
  if (digitalRead(button4) == LOW){             //if 4oz button is pressed
    //open solenoid 1, lemonade
    //open solenoid 2, tea
    delay(2000);  
    //close 1
    delay(2000)
    //close 2
  }

  else if (digitalRead(button8) == LOW){             //if 8oz button is pressed
    //open solenoid 1 
    //open solenoid 2  
    delay(4000);
    //close 1
    delay(4000); 
    //close 2
  }

  else if (digitalRead(button12) == LOW){            //if 8oz button is pressed
    //open solenoid 1 
    //open solenoid 2  
    delay(6000); 
    //close 1
    delay(6000); 
    //close 2
  }
         
  //solenoids close backup

  //mix via motor 

  //display done message
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("Done!");
}
