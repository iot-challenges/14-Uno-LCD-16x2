/**
 *
 *****************************************************************
 * IOT Challenges - https://instagram.com/iotchallenges          *
 *****************************************************************
 * Evandro Fruhauf                                               *
 *  GitHub - https://github.com/evandrodp                        *
 *  LinkedIn - http://linkedin.com/in/evandrofruhauf             *
 *****************************************************************
 * This code can contain parts from other open-sources projects, *
 * whenever possible it will be quoted.                          *
 *****************************************************************
 *
 * LCD 16x2
 *
 * Challenge: Write some text, blink and scroll it on the LCD 16x2
 *
 * This source is using the LiquidCrystal library by Malpartida. (Installed by PlatformIO)
 *
  **/
#include <Wire.h>
#include <LiquidCrystal.h>

// define the lcd ports
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// define the methods
void textWelcome();
void blinkLcd();
void scrollText();

void setup() {
  lcd.begin(16,2); // initialise the lcd
}

void loop() {
  textWelcome();
  for (int i = 0; i < 3; i++) {
    blinkLcd();
  }
  scrollText();
}

void textWelcome() {
  lcd.home(); // go home 0, 0
  lcd.print("IOT CHALLENGES");
  lcd.setCursor ( 0, 1 );
  lcd.print ("Share this post!");
}

void blinkLcd() {
  lcd.noDisplay(); //turn off the LCD display
  delay(350);
  lcd.display(); //turning on the LCD display
  delay(350);
}

void scrollText() {
  lcd.home(); // change the first line
  lcd.print("   INSTAGRAM:   ");
  lcd.setCursor ( 0, 1 ); // change the second line
  lcd.print("  IOTCHALLENGES ");
  delay(1000);
  for(int i = 0; i < 3; i++) {
    // Move till the corner
    for(int posCount=0; posCount<2; posCount++) {
      lcd.scrollDisplayLeft();
      delay(300);
    }
    // move to another corner
    for(int posCount=0; posCount<3; posCount++) {
      lcd.scrollDisplayRight();
      delay(300);
    }
    // move to original position
    for(int posCount=0; posCount<1; posCount++) {
      lcd.scrollDisplayLeft();
      delay(300);
    }
  }
  delay(1000);
}
