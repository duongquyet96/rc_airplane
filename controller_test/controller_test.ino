#include <PS4Controller.h>
#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <WiFi.h>

RF24 radio(12, 14, 33, 35, 32);
byte addresses[][6] = {"1Node","2Node"};
int bat_stat[1];
int notify = 0;
int notify2 = 0;

struct MyData
{
  uint8_t throttle;
  signed char aileron;
  signed char elevator;
  signed char ruder;
};
MyData Data;

signed char b[2];
bool hold = false;

void onEvent()
{
  uint8_t power; 
  if(PS4.L1() == true)
  {
    hold = !hold;   
  }
  if(hold == true)
  {
    power = Data.throttle;
    //Serial.println("Holding power");
  }
  if(hold == false)
  {
    power = PS4.data.analog.button.r2;
    //Serial.println("Manual power");
  }
  signed char l_stickY = PS4.LStickY();
  signed char r_stickX = PS4.RStickX(); 
  Data.throttle = power;
  Data.elevator = l_stickY;
  Data.ruder = r_stickX;
  //printResult();
}
 
void onConnection() 
{
  if (PS4.isConnected()) 
  {
    Serial.println("Controller connected.");
  }
}

void printResult()
{
  Serial.print("X: ");
  Serial.println(Data.ruder);
  Serial.print("Y: ");
  Serial.println(Data.elevator);
  Serial.print("Z: ");
  Serial.println(Data.throttle);
}
void setup()
{
  Serial.begin(115200);
  Serial.print("ESP Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
// RC var
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  //radio.openWritingPipe(0xE8E8F0F0E1LL);
  radio.openWritingPipe(0xE8E8F0F0E1LL);
  //radio.openReadingPipe(1,addresses[0]);
  radio.enableAckPayload();
  radio.stopListening();
//   
  if(!PS4.begin("24:6F:28:7B:49:B0"))
  {
      Serial.println("Initializetion failed");
      return;
  }
  Serial.println("Initialization finished.");
    
  PS4.attach(onEvent);
  PS4.attachOnConnect(onConnection);
}
 
void loop()
{
  if(bat_stat[0] == 111)
  {
    Serial.println("LOW BATTERY");
    PS4.setLed(255,0,0);
    notify = 1;
  }
  if(notify == 1 && notify2 == 0 && PS4.isConnected())
  {
     PS4.sendToController();
     notify2 = 1;
  }
  bool tx_sent;
  tx_sent = radio.write(&Data, sizeof(MyData));
  printResult();
  delay(1000);
  if (tx_sent) 
  {
    if (radio.isAckPayloadAvailable()) 
    {
      radio.read(&bat_stat, 1);
    }
  }
}
