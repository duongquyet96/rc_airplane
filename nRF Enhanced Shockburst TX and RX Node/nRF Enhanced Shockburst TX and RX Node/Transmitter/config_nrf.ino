void config_nrf_tx()
{
  write_reg_bit(nrf_config,1,1);          //power up
  write_reg_bit(0x00,0,0);                //TX Mode
  
  write_reg_bit(0x00,6,1);                //RX_DR disable
  write_reg_bit(0x00,5,1);                //TX_DS enable
  write_reg_bit(0x00,4,0);                //RT ensable
  
  send_byte(flush_rx);
  send_byte(flush_tx);
  
  write_reg(en_rx_addr,0x01);             //Enable RX address pipe 0
  write_reg(setup_aw,0x01);               //first two bits of setupt_aw =01 means 3 byte address length
  write_addr_reg(0x0a,rx_tx_addr);        //write RX pipe address in register
  write_addr_reg(0x10,rx_tx_addr);        //write TX address in register

  write_reg(en_AA,0x01);                  //Enable shock burst in case
  write_reg(setup_retr,0x23);             //set retries to 3 with 750us delay
  
  write_reg(rf_ch,0x01);                  //RF channel 1
  write_reg(rf_setup,0x26);               // 250kbps
  write_reg(feature_reg,0x00);

  attachInterrupt(0,ISR_NRF,FALLING); //attach interrupt..when data is transmitted nrf pulls down interrupt 0 pin of arduino and update_tx_buffer is called
  delay(20);
}
