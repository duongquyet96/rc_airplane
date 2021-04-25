void ss_low()
{
  digitalWrite(SS_PIN,LOW);
}

void ss_high()
{
  digitalWrite(SS_PIN,HIGH);
}

void set_sck_mode_order()
{
  set_sck();
  set_mode();
  set_data_order();
}

void set_sck()
{
  SPCR&=0xFC;
  SPSR|=0x01;
}


ISR(SPI_STC_vect)
{
  Serial.print("\nArduino ISR CALLED");
}
