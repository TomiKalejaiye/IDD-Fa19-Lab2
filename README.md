# Digital Timer

## Part A. Solder your LCD panel

![LCD with soldered pins](https://imgur.com/Hcuumnr.jpg)

## Part B. Writing to the LCD

![LCD Arduino Wiring Schematic](https://imgur.com/nJsVWop.png)
 
**a. What voltage level do you need to power your display?**

 VDD refers to the input positive power supply for a FET logic based integrated circuit. As seen in the diagram above, 5V is applied at the VCC pin for the LCD. Therefore 5V is required to power the display.

**b. What voltage level do you need to power the display backlight?**

 The positive voltage supply for the display backlight is at pin 15, and we need 3.3V there.
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**

 I didn't really make any mistakes while wiring up the display. I almost put the display in upside down, but then I looked at the pin labels on the back, and reversed it.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**

 In the "HelloWorld.ino" example code, the command to print "hello, world!" is in the setup() loop on line 55. By simply changing the argument of lcd.print() to "Tomi" I can make the LCD display my name. Then in loop() I write lcd.noDisplay() followed by delay(time), then lcd.display() followed by delay(time). This will make the LCD flash with whatever has been printed to it (in this case my name) being displayed. Changing the arguments of the delay() function calls will determine the frequency of the flashing.
 
 In the setup():
 ```
 lcd.print("Tomi");
 ```
 and in the loop():
 ```
    lcd.display();
    delay(500);
    lcd.noDisplay();
    delay(500);
```
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**

[![Lowly Multimeter video](http://img.youtube.com/vi/--P7Cqi50Mo/0.jpg)](https://www.youtube.com/watch?v=--P7Cqi50Mo)

[Lowly Multimeter Code](https://github.com/TomiKalejaiye/IDD-Fa19-Lab2/blob/master/LowlyMultimeter.ino)


## Part C. Using a time-based digital sensor

[![Working Rotary Encoder](http://img.youtube.com/vi/BJTETgxkXLU/0.jpg)](https://www.youtube.com/watch?v=BJTETgxkXLU)

## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**

In the setup portion of the example code, the variable noteDuration is calculated by taking one second (1000ms) and dividing it by the note duration for the note type that is to be played. If I instead divide half a second (500ms) by the duration for the same note type, it will be played twice as fast. Therefore in the calculation of noteDuration, simply change 1000 to 500:

```
int noteDuration = 1000 / noteDurations[thisNote];
```
to
```
int noteDuration = 500 / noteDurations[thisNote];
```

 
**b. What song is playing?**

The Arduino example code plays the famous "Shave and a Haircut, two bits" call and response couplet. Upon updating the code with the notes provided, it plays the Star Wars intro theme.

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

[![Rotary Encoder Countdown Timer](http://img.youtube.com/vi/EvXgpOWEWsE/0.jpg)](https://www.youtube.com/watch?v=EvXgpOWEWsE)

This video shows the operation of my timer. It uses a pushbutton rotary encoder to manually set a time which is displayed on the LCD in seconds. When the button is pressed, a timer begins. When the time is up, a "Game Over!" message is displayed for 5 seconds. My code for this timer can be found [here](https://github.com/TomiKalejaiye/IDD-Fa19-Lab2/blob/master/Timer.ino).

Note: The timer cannot be stopped once it begins counting down, until it finishes, displays the message, and resets. Pushing the button will do nothing until it has reset.

