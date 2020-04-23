/*    attention 

Du au limitations de tinkerCad, certains composants on �t�
remplac�s par d'autres solution pour les test :
detection RFID : int�rupteur glissi�re
envoie de donn�e via smartphone : pav� num�rique
affichage donn�e sur smartphone : console
ventillateur : led bleu
resistance chauffante : led rouge

*/
#include <Adafruit_NeoPixel.h>

#define PIN 5	 // input pin Neopixel is attached to

#define NUMPIXELS      12 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



int pinFan = 4;
int pinHeat = A0;
int pinRes = 2;

String readString;

const int STANDBY = 1;
const int WORKING = 2;
const int READY = 3;


void setup()
{
  Serial.begin(9600);
  
  pinMode(pinFan, OUTPUT);
  pinMode(pinRes, OUTPUT);
  pinMode(pinHeat, INPUT);
  
  digitalWrite(pinFan, LOW);
  digitalWrite(pinRes, LOW);
  
  //Passer led statut a bleue
  setLedStatus(STANDBY);
  
  
}

void loop()
{
  String tempUserString ="";
  int readOK = 0;
  //detecter la temperature
  float temperatureMug = lectureTemp();

  //afficher la temperature
  Serial.print(" la temperature est de " + String(temperatureMug));
  Serial.println(" degres C");
  delay(50);

  //attendre input utilisateur (ici, deux caract�res via console)
  Serial.println("Rentrez la temp�rature voulue : ");
  int userTemp = getUserTemp();

  //allumer ventilateur OU allumer resistance
  if((float)userTemp < temperatureMug){
    digitalWrite(pinFan, HIGH);
    digitalWrite(pinRes, LOW);
    
  //allumer led statut en rouge
  setLedStatus(WORKING);
    
  }
  else if((float)userTemp > temperatureMug){
    digitalWrite(pinRes, HIGH);
    digitalWrite(pinFan, LOW);
    
  //allumer led statut en rouge
  setLedStatus(WORKING);
    
  }
  else{
    
  //allumer led statut en vert
  setLedStatus(READY);
  }
  
  while((float)userTemp > temperatureMug || (float)userTemp > temperatureMug){
    temperatureMug = lectureTemp();
    Serial.print(" temperature du mug : ");
    Serial.print(temperatureMug);
    Serial.println(" degr�s celcius ");
    
    if(temperatureMug > 60){
      Serial.println("ERROR : temperature trop elev�");
    }
  }
  
  //temperature OK, eteindre les composants
  digitalWrite(pinRes, LOW);
  digitalWrite(pinFan, LOW);

  //atteindre bonne temp�rature
  //allumer led en vert pendant 2 minutes
  setLedStatus(READY);
  delay(8000);
  //allumer led en bleu
  setLedStatus(STANDBY);
}

void setLedStatus(int status){
  Serial.println("setting status led");
  switch (status) {
  case STANDBY://bleu
  for (int i=0; i < NUMPIXELS; i++) {
	pixels.setPixelColor(i, pixels.Color(0, 0, 255));
  }
    break;
  case WORKING://red
    for (int i=0; i < NUMPIXELS; i++) {
		pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  	}
    break;
   case READY://green
    for (int i=0; i < NUMPIXELS; i++) {
		pixels.setPixelColor(i, pixels.Color(0, 255, 0));
  	}
    break;
  default:
    break;
	}
  pixels.show();
  
}

float lectureTemp(){
  	int reading = analogRead(A0);  
	float volt = reading * 5.0;
 	volt = volt / 1024.0; 
  	float temperature = (volt - 0.5) * 100 ;
  	return temperature;
}

int getUserTemp(){
  int n;
  int hasReceivedValue = 0;
  while(hasReceivedValue == 0){
    while (Serial.available()) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the String readString
      delay(2);  //slow looping to allow buffer to fill with next character
    }

    if (readString.length() >0) {
      Serial.println(readString);  //so you can see the captured String
      n = readString.toInt();  //convert readString into a number
      Serial.print("tempereature : ");
      Serial.println(n);
      readString="";
      hasReceivedValue = 1;
    }
  } 
  return n;
}


