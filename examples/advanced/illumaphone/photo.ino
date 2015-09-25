// Reads values from the 6 photoresistors and prints them out over USB to serial.
float analogPins[] = {A0, A1, A2, A3, A4, A5};

SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() 
{ 
    Serial.begin(9600);
} 
 
 
void loop() 
{ 
  for (int i = 0; i < 6; i++)
  {
    int val = analogRead(analogPins[i]);
    Serial.print(val);
    Serial.print(" ");
  }
  Serial.println();
}