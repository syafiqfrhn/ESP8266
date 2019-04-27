# Real Time Parking System Monitoring Using Google Sheets

The prototype of the parking system consist of four *HC-SR04* ultrasonic sensors, two *Arduino Mega*, and an *ESP-8266* Wi-Fi module as part of hardware components. For the software parts, *Google Sheets* acts as a simplified database, and *Google HTML Service* web pages were used to display the availability of parking spaces in real-time.

This system makes of **HTTPS Redirect library** from **electronicsguy**. The files used and modified in this system are **GoogleDocs.ino** and **GoogleScript.gs**. The original files are located in the **HTTPSRedirect** directory.

This system was developed on July 2018.

## Components and Operations

This system makes up of three main parts; the input & processing unit, the communication unit, and the output & database.

### Input & Processing Unit

Each parking space consist of one *HC-SR04* ultrasonic sensor which acts as an input to determine whether the parking space is vacant or occupied. The sensor operates at 40 kHz, 5V, and 15mA of current. Also, the range of the detectable distance from the sensor is between 2cm to 4m. 

Each sensor is connected to an *Arduino Mega* microcontroller board which acts as a processing unit for the system. The board can be powered by either an external AC-to-DC adapter or by an USB cable type A/B to provide a constant power supply to the system.

### Communication Unit

There are many methods of communication available in order to make the system to be able to communicate with the *Google Sheets* via Internet. In this system, the methods of communication used is *ESP8266 ESP-01* Wi-Fi module. The module provides the capability to wirelessly connect to a Wi-Fi network to transmit and receive data. It uses 2.4 Hz Wi-Fi (802.11 b/g/n) specification that supporting WPA/WPA2. As the module itself is a microcontroller chip, it needs to be programmed first in order to use it.

### Output & Database

The data from sensors are stored in the *Google Sheets* which acts a simplified database. Google Sheets can be scripted using *Google Apps Script* to create and modify spreadsheets. *Google Apps Script* is a *JavaScript* cloud scripting language that is executed in *Google Cloud* instead of running in the client-side.

In the system, *Google Sheets* is used to store and keep track of the data regarding the parking availability. To display the data in a more interactive and user-friendly format, the *Google HTML Service* is used to create user interface in the form of web pages. Hence, *Google Apps Script* acts as a link between *ESP8266* Wi-Fi module & *Google Sheets*, and also between *Google Sheets* & the web pages.
