# Digital Timer
 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

[LCD with soldered pins](https://imgur.com/Hcuumnr.jpg)

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
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
 
**b. What song is playing?**


## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
