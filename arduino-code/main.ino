#include <ArduinoJson.h>

const int TAMANHO = 100;

int TermistorPin = A1;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf, temp;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; //valores constante para calculo
int UVPin = A0;
float uv;

void setup(){
	pinMode(13,OUTPUT);
	pinMode(UVPin, INPUT);
  	pinMode(TermistorPin, INPUT);
	Serial.begin(9600);
}

void loop(){
	delay(30000);
	
	StaticJsonDocument<TAMANHO> json;
    
  	temp = readTemp(TermistorPin);

  	uv = readUV(UVPin);

  	json["sensortemp"] = temp;
  	json["sensoruv"] = uv;
	json["sensorph"] = map(analogRead(A2), 0,1023,0,14);
	
	serializeJson(json, Serial);
	Serial.println();
	
	
	if (Serial.available() > 0) {
		String dado = Serial.readString();
		if(dado=="warning"){
			digitalWrite(13,!digitalRead(13));
			delay(1000);
		}
	}
}

float readTemp(int ThermistorPin){
  	Vo = analogRead(ThermistorPin);
  	R2 = R1 * (1023.0 / (float)Vo - 1.0);
  	logR2 = log(R2);
  	T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));// Equação de Steinhart–Hart 
 	Tc = T - 273.15;
  	return Tc;
}

float readUV (int UVPin){
	float Vout,RLDR,Lux;
	int ADC;
	float Rdark = 127410.0;
	ADC = analogRead(UVPin);
	RLDR = R1 * (1023.0 / (float)ADC - 1.0);
	Lux = pow(Rdark/RLDR,1/0.8582);
	return Lux;
}
