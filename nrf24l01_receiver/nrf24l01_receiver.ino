#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
char msg[6];
RF24 radio(7,8);

void setup(void){
 Serial.begin(115200);
 radio.begin();
 radio.setChannel(2);
 radio.setPayloadSize(7);
 radio.setDataRate(RF24_250KBPS);
 radio.openReadingPipe(1,0xE8E8F0F0E1LL);
 radio.startListening();
}

void loop(void){
 if (radio.available()){  
     radio.read(msg, 6);      
     Serial.println(msg);
     delay(10);
 }
 else{
  //Serial.println("No radio available");
 }
}
