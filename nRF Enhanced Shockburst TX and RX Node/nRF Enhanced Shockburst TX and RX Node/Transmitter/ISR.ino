void ISR_NRF()
{
  byte status_nrf;
  status_nrf=read_reg(nrf_status);
  
  if((status_nrf>>5) & 0x01)
    update_tx_buffer();
  if((status_nrf>>4) & 0x01)
    max_rt();
}

void update_tx_buffer()
{
  Serial.print("\nData transmitted and acked");
  write_reg_bit(0x07,5,1);    //clear flag most imp part
}

void max_rt()
{
  Serial.print("\nMaximum Number of Retransmit reached");
  write_reg_bit(nrf_status,4,1);
}
