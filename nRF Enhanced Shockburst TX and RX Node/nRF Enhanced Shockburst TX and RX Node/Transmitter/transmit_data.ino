void transmit_data()
{
  send_byte(flush_tx);
  ss_low();
  data_in[0]=send_byte_ns(wt_tx_payload);         //instruction to load tx buffer
  
  data_in[2]=send_byte_ns(analogRead(A0)/4);      //data byte 1
  data_in[3]=send_byte_ns(analogRead(A1)/4);      //data byte 2
  data_in[4]=send_byte_ns(analogRead(A2)/4);      //data byte 1
  data_in[5]=send_byte_ns(analogRead(A3)/4);      //data byte 2
  ss_high();

  
  digitalWrite(CE_PIN,LOW);                 //actual transmission starts now
  delay(20);                                //delay is essential
  digitalWrite(CE_PIN,HIGH);                //end transmisssion
  Serial.print("\nData Transmitted");
}
