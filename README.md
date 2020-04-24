#titre projetIOTMESGI


## Introduction

The system enables its user to either heat or cool down the content of an object. Thanks to its electrical system (heat resistance or ventilation) the wall of any object that sustain heat or cold will be adjusted. With the help of an interface, the user will be able to control the temperature of the object it is attached to and insert the temperature needed he would like. 
This system is made to heat or cool down liquids. 


## How it works

The box connect to a mug through either an adapter or directly to the mug. Our mugs are specialised to accomodate to the device. Once connected, there is a ligh signal to notice its user it is connected. Through an interface, the user is able to set the temperature he would like for his liquid to be heated or cool down.The system will automatically be turned down when the temperature set is reached or if the user forgets his mug set on on.

## Hardware

#### Arduino Nano
![ArduinoNano](https://user-images.githubusercontent.com/25655382/80193736-a643ff80-8619-11ea-9a15-a2dd49cb21b1.JPG)

#### BreadBoard

![Bboard](https://user-images.githubusercontent.com/25655382/80186337-219fb400-860e-11ea-84fd-c3b88b63d84b.JPG)

#### Résistance 

![1280px-3_Resistors](https://user-images.githubusercontent.com/25655382/80209985-3f334480-8633-11ea-865c-0b81b504f60f.jpg)

#### Interrupteur Glissière

![interrupteurGlissiere](https://user-images.githubusercontent.com/25655382/80114142-7b0ed100-8583-11ea-9df4-b39672bf626c.jpg)

#### HC-05 Bluetooth Module

![61pby065esl__sx679__tNr8sYwW5D](https://user-images.githubusercontent.com/25655382/80210404-047ddc00-8634-11ea-93fe-0a63779e26b9.png)

#### LED RGB

![led](https://user-images.githubusercontent.com/25655382/80186229-f74df680-860d-11ea-9b78-7f4f9fb941c9.JPG)


#### Capteur de Température

![temp](https://user-images.githubusercontent.com/25655382/80186901-0d0feb80-860f-11ea-951f-9e281f355958.png)


#### Ventilateur

![Ventilateur1](https://user-images.githubusercontent.com/25655382/80187548-1cdbff80-8610-11ea-8fb1-f478eb012a1e.jpg)

#### Resistance Chauffante 
![61ksLhWC20L _AC_SL1000_](https://user-images.githubusercontent.com/25655382/80187267-a0492100-860f-11ea-9d12-52c5d51957d7.jpg)

### Lipo
![lipo](https://user-images.githubusercontent.com/25655382/80189469-fec3ce80-8612-11ea-9600-cc7c2eea8839.JPG)

### Charge lipo
![Chargelipo](https://user-images.githubusercontent.com/25655382/80189605-37fc3e80-8613-11ea-9994-03f85e14e3ff.JPG)

## Software 

* Arduino IDE : available her https://www.arduino.cc/en/main/software

## Cabling
We simulated the cabling using the TinkerCad application in order to show how the components work together and their cabling.<br/>
However, due to tinkerCad's restriction,some components have been replaced by others to make it work and for tests purposes :<br/>
detection RFID : intérupteur glissière<br/>
envoie de donnée via smartphone : simulé par la console<br/>
affichage donnée sur smartphone : console<br/>
ventillateur : led bleu<br/>
resistance chauffante : led rouge

![cabling](https://user-images.githubusercontent.com/25655382/80202760-6899a380-8626-11ea-8f33-26cafc6183d8.JPG)
