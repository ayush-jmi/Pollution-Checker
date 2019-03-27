# Pollution-Checker

In this project, we are showing the amount of PPM10 (present in air using MQ135) and upload it online after checking whether wifi connection is available or not as well as,  internet connection is available or not. It refresh its reading after every one second on 16*2 Liquid Crystal Display (LCD) and upload a new value online after every one minute thirty seconds online. In starting, it waits fifteen minutes so that MQ135 gets time to heat up and starts showing correct value. It consists of internally installed battery to power it.

COMPONENTS

The components used to make it are:-
1)	NodeMCU (ESP8266): NodeMCU is an open source Internet of Things platform with embedded controller that is programmed through Arduino IDE, to handle analog and digital received from sensors and to print data on OLED display. I use ESP8266 in place of Arduino UNO because dynamic memory of Arduino UNO is 2048 bytes and only one image can be uploaded in the code while ESP8266 has 81920 of dynamic memory and we can upload around 50 images in it.
2)	Pollution Sensor (MQ135): Sensitive material of MQ135 gas sensor is SnO2, which with lower conductivity in clean air. When the target combustible gas exist, the sensor’s conductivity is more higher along with the gas concentration rising. Please use simple electro circuit, Convert change of conductivity to correspond output signal of gas concentration. MQ135 gas sensor has high sensitivity to Ammonia, Sulfide and Benze steam, also sensitive to smoke and other harmful gases. It is with low cost and suitable for different application. It can detect particles of range 10 to 1000 PPM.
3)	16*2 Liquid Crystal Display: This is a basic 16 character by 2 line display. Black text on Green background. Interface code is freely available. You will need 11 general I/O pins to interface for 16 bit code and 6 general I/O pins to interface for 8 bit code.
4)	Power Source: Simple power bank Printed Circuit Board (PCB) connected with the Lithium Ion cells to power the device.
CIRCUIT & WORKING
The circuit diagram is shown in the fig. It is build around NodeMCU (ESP8266), MQ135 sensor, 16*2 LCD display, and power source.
 The circuit has analog input to read value of pollution through MQ135 and LCD to display data of MQ135.
Battery of 5V, 8000mAh is connected to power the device.
 
SOFTWARE

The code is written in Arduino programming language using Arduino IDE, which allows writing the code within few lines. 

To add board for ESP8266 in Arduino IDE, go to ->File ->Preferences and paste the below link in Additional Board Manager URLs.

https://arduino.esp8266.com/stabl/package_esp8266com_index.json

Open Boards Manager from Tools ->Board menu and install esp8266 platform. (Do not forget to select your NodeMCU board from Tools ->Board menu after installation).

You can download the code from the link below.

https://github.com/ayush-jmi/Pollution-Checker/blob/master/Pollution_Checker.ino


**It will start updating data online 15 minutes after power is on so that MQ135 can take accurate readings.**
