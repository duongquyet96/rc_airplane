void display_pwm()
{
  Serial.print("\nPWM VALUES\t");
  Serial.print(data_in[2]*4+1000);
  Serial.print("\t");
  Serial.print(data_in[3]*4+1000);
  Serial.print("\t");
  Serial.print(data_in[4]*4+1000);
  Serial.print("\t");
  Serial.print(data_in[5]*4+1000);
  Serial.print("\n\n");
  
}
void display_register()
{
  Serial.print("\nnrf_config ");
  Serial.print(read_reg(nrf_config),HEX);

  Serial.print("\nen_shock_burst ");
  Serial.print(read_reg(en_AA),HEX);

  Serial.print("\nen_rx_addr ");
  Serial.print(read_reg(en_rx_addr),HEX);

  Serial.print("\nsetup_aw ");
  Serial.print(read_reg(setup_aw),HEX);

  Serial.print("\nsetup_retr ");
  Serial.print(read_reg(setup_retr),HEX);

  Serial.print("\nrf_ch ");
  Serial.print(read_reg(rf_ch),HEX);

  Serial.print("\nrf_setup ");
  Serial.print(read_reg(rf_setup),HEX);

  Serial.print("\nnrf_status ");
  Serial.print(read_reg(nrf_status),HEX);

  Serial.print("\nobserve_tx ");
  Serial.print(read_reg(observe_tx),HEX);

  Serial.print("\nrpd ");
  Serial.print(read_reg(rpd),HEX);

  Serial.print("\nrx_addr_p0 ");
  Serial.print(read_reg(rx_addr_p0),HEX);

  Serial.print("\nrx_addr_p1 ");
  Serial.print(read_reg(rx_addr_p1),HEX);

  Serial.print("\nrx_addr_p2 ");
  Serial.print(read_reg(rx_addr_p2),HEX);

  Serial.print("\nrx_addr_p3 ");
  Serial.print(read_reg(rx_addr_p3),HEX);

  Serial.print("\nrx_addr_p4 ");
  Serial.print(read_reg(rx_addr_p4),HEX);

  Serial.print("\nrx_addr_p5 ");
  Serial.print(read_reg(rx_addr_p5),HEX);

  Serial.print("\ntx_addr ");
  Serial.print(read_reg(tx_addr),HEX);

  Serial.print("\nrx_pw_p0 ");
  Serial.print(read_reg(rx_pw_p0),HEX);
  
  Serial.print("\nrx_pw_p1 ");
  Serial.print(read_reg(rx_pw_p1),HEX);
  
  Serial.print("\nrx_pw_p2 ");
  Serial.print(read_reg(rx_pw_p2),HEX);
  
  Serial.print("\nrx_pw_p3 ");
  Serial.print(read_reg(rx_pw_p3),HEX);

  Serial.print("\nrx_pw_p4 ");
  Serial.print(read_reg(rx_pw_p4),HEX);
  
  Serial.print("\nrx_pw_p5 ");
  Serial.print(read_reg(rx_pw_p5),HEX);

  Serial.print("\nfifo_status ");
  Serial.print(read_reg(fifo_status),HEX);

  Serial.print("\ndyn_payload ");
  Serial.print(read_reg(dyn_payload),HEX);

  Serial.print("\nfeature_reg ");
  Serial.print(read_reg(feature_reg),HEX);
}

void display_recv_data()
{
  Serial.print("\nRecieved Bytes\t");
  Serial.print(data_in[2],DEC);
  Serial.print('\t');
  Serial.print(data_in[3],DEC);
  Serial.print('\t');
  Serial.print(data_in[4],DEC);
  Serial.print('\t');
  Serial.print(data_in[5],DEC);
}
