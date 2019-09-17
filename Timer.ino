/*
Timer

 Uses a rotary encoder to manually set and start a timer.

 Created by Tomi Kalejaiye

 16 Sep. 2019
 
 */

#include <LiquidCrystal.h>
#define ENC_A 6 
#define ENC_B 7
#define PUSH 9

int aPos;    
int prev_aPos;
int tick = 0; //time manually set for timer
 
int buttonPos = HIGH;
int prev_buttonPos = HIGH;

int start_time;
int time_left;

//Creating the display object
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  //set encoder pins as inputs
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(PUSH, INPUT_PULLUP);

  //set last known encoder position.
  prev_aPos = digitalRead(ENC_A);

  //Initialize the display
  lcd.begin(16, 2);
  
}

void loop() {
  //start cursor at leftmost topmost cell
  lcd.setCursor(0,0);
  //print the voltage
  lcd.print(setTime());
  lcd.print(" ");
  //move cursor to display the unita
  lcd.setCursor(5,0);
  //print s for seconds
  lcd.print("s");
  /*Checking whether the button has been pushed, and starting the timer when it has*/
  if(checkButton() == HIGH){
    startTimer();
  }
}


int setTime(){
  /*Uses the encoder position to change the time setting. Changes from LOW to HIGH let show that the
  encoder is turning, and which signal (A or B) goes HIGH first tells us which direction we are moving*/
  aPos = digitalRead(ENC_A);
  int bPos = digitalRead(ENC_B);
  /*Change int time value is triggered on rising edge of A encoder signals*/
  if ((prev_aPos ==LOW) && (aPos==HIGH)){
    /*If B encoder signal is not equal to A encoder signal
    then we know we are going from both A and B being LOW, to only A being HIGH.
    This means we are going clockwise, and should increment.*/
      if (bPos != aPos){
      tick++;
    } else {
      if (tick > 0){
        /*If A and B are equal, and A has just gone HIGH, then B was HIGH first, and 
        we are going counterclockwise, and should decrement*/
        tick--;
      } else{
        return 0;
      }
    }
  }
  //update position
  prev_aPos = aPos;
  return tick;
}

int checkButton(){
  /*Returns HIGH if button has been pushed and LOW if not.*/
  buttonPos = digitalRead(PUSH);
  int pushed = LOW;
  /*Checks if there has been a change in the position of the button*/
  if (buttonPos != prev_buttonPos) {
    /*Only consider button pushed after button has been released.
    Since we use a pullup resistor, buttonPos will be HIGH when the button is released.*/
    if (buttonPos == HIGH) {
      /*this is set to prepare for timing to begin*/
      time_left = tick;
      pushed = HIGH;
    } 
  }
  //update button position
  prev_buttonPos = buttonPos;
  return pushed;
}

void startTimer(){
  /*Note the current time (relative to program start)*/
  start_time = millis() / 1000;
  while (time_left > 0){
    int current_time = millis() / 1000;
    /*Calculate time elapsed by taking the current time at every loop and subtracting start_time
    from that.*/
    int time_elapsed = current_time - start_time;
    /*Calculate time leftover by subtracting time elapsed from the time we set for the timer.*/
    time_left = tick - time_elapsed;
    /*Print out time left as it goes down*/
    lcd.setCursor(0,0);
    lcd.print(time_left);
    lcd.print(" ");
  }

  /*Print a game over message. I will likely be integrating this timer
  into a game in the future.*/
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GAME");
  lcd.setCursor(0,1);
  lcd.print("OVER!");
  delay(5000);
  lcd.clear();
}
