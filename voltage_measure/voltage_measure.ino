
void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  double value1 = analogRead(A0);
  double voltage1 = value1 * 4.978/1024;
  double value2 = analogRead(A1);
  double voltage2 = value2 * 4.978 * 2 /1024 ;
  double value3 = analogRead(A2);
  double voltage3 = (value3 * 4.978) * 11 / 1024; 
  Serial.print("Voltage 1: ");
  Serial.println(voltage1);
  Serial.print("Voltage 2: ");
  Serial.println(voltage2);
  Serial.print("Voltage 3: ");
  Serial.println(voltage3+0.1);
  Serial.println(" ");
  delay(1000);

}
