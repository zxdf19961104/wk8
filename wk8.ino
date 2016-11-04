int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int greenPin = 6;
int redPin = 9;
int bluePin = 5;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
// initialize serial communications at 9600 bps:
pinMode(greenPin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(bluePin,OUTPUT);
Serial.begin(9600);
}

void loop() {
// read the analog in value:
sensorValue = analogRead(analogInPin);
// map it to the range of the analog out:
outputValue = map(sensorValue, 0, 900, 0, 255);
// change the analog out value:
if(outputValue < 255/3){
analogWrite(greenPin,map(outputValue,0,255/3,0,255));
analogWrite(redPin,map(outputValue,0,255/3,0,255));
analogWrite(bluePin,0);
}
else if(outputValue < 255/3*2 && outputValue > 255/3){
analogWrite(greenPin,map(outputValue,255/3,255/3*2,0,255));
analogWrite(redPin,0);
analogWrite(bluePin,map(outputValue,255/3,255/3*2,0,255));
}
else{
analogWrite(greenPin,0);
analogWrite(redPin,map(outputValue,255/3*2,255,0,255));
analogWrite(bluePin,map(outputValue,255/3*2,255,0,255));
}
   // print the results to the serial monitor:
Serial.print("sensor = " );
Serial.print(sensorValue);
Serial.print("\t output = ");
Serial.println(outputValue);

delay(2);
}

