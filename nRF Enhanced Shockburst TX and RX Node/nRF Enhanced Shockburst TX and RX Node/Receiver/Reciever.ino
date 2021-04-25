#include <Servo.h>

//Uno Recieves
#define MOSI_PIN 11
#define MISO_PIN 12
#define SCK_PIN 13
#define SS_ARD_PIN 10
#define SS_PIN 9
#define CE_PIN 8  //CE HIGH for RX
#define IRQ 2

// nrf instructions

#define flush_tx 0b11100001
#define flush_rx 0b11100010

#define rd_rx_payload 0b01100001
#define wt_tx_payload 0b10100000

#define set_mode() SPCR&=0xf3
#define set_data_order() SPCR&=0xdf
#define begin_spi() SPCR|=0x40

//register addresses

#define nrf_config     0x00
#define en_AA 0x01
#define en_rx_addr     0x02
#define setup_aw       0x03
#define setup_retr     0x04
#define rf_ch          0x05
#define rf_setup       0x06
#define nrf_status     0x07
#define observe_tx     0x08
#define rpd            0x09
#define rx_addr_p0     0x0a
#define rx_addr_p1     0x0b
#define rx_addr_p2     0x0c
#define rx_addr_p3     0x0d
#define rx_addr_p4     0x0e
#define rx_addr_p5     0x0f
#define tx_addr        0x10
#define rx_pw_p0       0x11
#define rx_pw_p1       0x12
#define rx_pw_p2       0x13
#define rx_pw_p3       0x14
#define rx_pw_p4       0x15
#define rx_pw_p5       0x16
#define fifo_status    0x17
#define dyn_payload    0x1c
#define feature_reg    0x1d

byte data_in[6],rx_tx_addr[3]={0x1a,0x2b,0x3c};

Servo ch1,ch2,ch3,ch4;

void setup()
{
  Serial.begin(115200);
  ch1.attach(3);
  ch2.attach(4);
  ch3.attach(5);
  ch4.attach(6);
  init_spi();                     //intialize SPI on arduino
  set_sck_mode_order();           //set clock rate mode and data order
  begin_spi();                    //set SPI enable bit in SPCR
  config_nrf_rx();                //configure as transmitter
  clear_interrupts();
  Serial.print("\nAll set..!!");
}

void loop()
{
  Serial.print("\nBoo");
  //uint32_t temp=micros();
  //test_spi();
  //display_register();
  //Serial.print("\nFrequency\t");
  //Serial.print(1/((micros()-temp)*0.000001));
  //Serial.print("\n");
  delay(10);
}

void clear_interrupts()
{
  write_reg_bit(0x07,4,1);
  write_reg_bit(0x07,5,1);
  write_reg_bit(0x07,6,1);
}


