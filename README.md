# 2015 HHCARD Cocktail Game (Arduino micro code) Readme

### Project Overview
This project comprised the HCARD (Human Centred Design of Assistive and Rehabilitation Devices) 
group project module at Imperial College London. 

Our group created a game designed to enhance rehabilitation experience for stroke patients.
By mimicking the arm motion required to make a cocktail, we hope to help recover hand and arm functions
of the patients via neuroplasticity. 

This repository contains the Arduino micro source code written for the project. The Arduino receives commands
from an Android phone via Bluetooth. The source code for the Android app can be found 
here: https://github.com/reginalio/HHCARDCocktailGame

The final version of the code can be found in `finalcode/finalcode_withbluetooth/finalcode_withbluetooth.ino`. Other folders consist of 
various tests we wrote during code development

### Build
Run on an Arduino micro with Bluetooth module HC-06 connected via RX/TX serial connection
