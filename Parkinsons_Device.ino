//Prototype code for Parkinson's rythym device, BME 66
//Version 1.0 March 2019
//Charlie DeLorey

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int led = 13;

//1000 = one second = one hertz (Hz)
//2.0 Hz is average walking gait 

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}


void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 1, 60);     // scale it to use with the LED (value between 1 and 60, seconds) 
  Serial.println(val);
  pinHertz(val, led);
} 

//function takes a frequency (in Hz [seconds]) and makes an led pulse at that freq
void pinHertz(int freq, int led) {
  digitalWrite(led, HIGH);
  delay(freq * 1000);
  digitalWrite(led, LOW);
  delay(freq * 1000);
}
