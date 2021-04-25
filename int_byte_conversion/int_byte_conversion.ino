int j;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  int i = -100;
  signed char b = i;
  j = b; 
}

void loop() 
{
  Serial.println(j);
  delay(1000);
}
