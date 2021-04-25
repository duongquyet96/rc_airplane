#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Servo.h>

Servo myservo;
Servo myservo2;
Servo motor;

struct MyData
{
  uint8_t throttle;
  signed char aileron;
  signed char elevator;
  signed char ruder;
};
MyData Data;

signed char b[2];
RF24 radio(7,8);
byte addresses[][6] = {"1Node","2Node"};
int bat_stat[1] = {000};

int recvData()
{
  if ( radio.available() ) 
  {
    Serial.println("received");
    radio.read(&Data, sizeof(MyData));
    return 1;
    }
    return 0;
}

void setup(void)
{
 Serial.begin(115200);
 Serial.println("Starting");
 radio.begin();
 radio.setDataRate(RF24_250KBPS);
 //radio.openReadingPipe(1,pipe);
 radio.openReadingPipe(1,0xE8E8F0F0E1LL);
 radio.enableAckPayload();
 radio.startListening();

 myservo.attach(3, 500, 2500);
 myservo2.attach(4, 500, 2500);
 motor.attach(2);
 motor.writeMicroseconds(1500);
 delay(2000);
}

void loop(void)
{
  double value1 = analogRead(A0);
  double voltage1 = value1 * 4.84/1024;
  double value2 = analogRead(A1);
  double voltage2 = value2 * 4.84 * 2 /1024 ;
  double value3 = analogRead(A2);
  double voltage3 = (value3 * 4.84) * 11 / 1024; 
  /*Serial.print("Voltage 1: ");
  Serial.println(voltage1);
  Serial.print("Voltage 2: ");
  Serial.println(voltage2);
  Serial.print("Voltage 3: ");
  Serial.println(voltage3+0.1);
  Serial.println(" ");*/
  /*if(voltage1 <= 3.73 && voltage2 <= 7.45 && voltage3 <= 11.18)
  {
    bat_stat[0] = 111;
    radio.writeAckPayload(1, bat_stat, 1);
    Serial.println("LOW BATTERY");
    Serial.println(voltage1);
    Serial.println(voltage2);
    Serial.println(voltage3);
  }
  else
  {
    bat_stat[0] = 000;
    radio.writeAckPayload(1, bat_stat, 1);
  }*/
  if (recvData())
  {  
    int s1 = map(Data.elevator, -128, 128, 0, 180);
    int s2 = map(Data.ruder, -128, 128, 0, 180);
    int p = map(Data.throttle, 0, 255, 1100, 2500);
    myservo.write(s1);
    myservo2.write(s2);
    motor.write(p);
    Serial.println(s1);
    Serial.println(s2);
    Serial.println(p);
  }
}
