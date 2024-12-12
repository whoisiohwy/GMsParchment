# GMs Parchment
Program for the M5Cardputer that allows DND (or other TTG) GM's to create things quickly


########################################################################


This tool is helpful for quickly generating the following: 

Enemies (whose attributes are dependent on the Party Level)
Weapons 
Armour
Potions
Scrolls
Items (Such as materials used to cast spells, gold, etc.)

Use this as you please - if running on a different platform (e.g., M5StickC, or any other pre-built box), feel free to adjust as neseccary to omit and include the requisite libraries; please also pay-it-forward and post your revised code so that others may use this if they are also using the platform you adjust it for. 
Thx <3


########################################################################


You'll find numerous arrays that are used to generate each thing, as well as arrays used to give those things (or enemies) attributes. Feel free to change any of this to suit the world which you are building. (Note: If you adjust the amount of data in any given array, you will need to find the corresponding "random(0,x) and change x to match the amount of data in the new array, see variable declarations and CTRL+F to get there quicker). 


########################################################################


HOW TO USE IT (specific to Cardputer): 

Use the LEFT and RIGHT arrow keys, or the 'A' and 'D' keys to navigate through the things that can be generated. 
Use the UP and DOWN arrow keys, or the 'S' and 'E' keys to navigate between Enemies and Loot. 

Click the 'Enter' ('OK') key to create the thing selected on screen. 

While in the Enemies list, or while drilled down into a specific enemy, you can use the '-' and '=' keys to increase or decrease the party level (note: this resets to 1 every time the device is turned off, fix coming eventually).

While drilled into Potions, Scrolls, or Items, you can use the '-' and '=' keys to increase or decrease the number of those items to be generated, from 1-7. 
-Using the 'Enter' ('OK') key will create a new set of the selected loot type using the same quantity. 
-If you are drilled into Potions, Scrolls, or Items, you can hit the '0' key and generate a random number of these.


########################################################################


Happy table-topping! 
