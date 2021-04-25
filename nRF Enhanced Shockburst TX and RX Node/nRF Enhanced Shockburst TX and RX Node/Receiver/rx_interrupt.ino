void get_data()                              //ISR for reciever
{
  Serial.print("\nRX Interrupt");
  ss_low();
  data_in[0]=send_byte_ns(rd_rx_payload);   //Instruction to read payload
  data_in[2]=send_byte_ns(0);               // Read data byte 1
  data_in[3]=send_byte_ns(0);               //Read data byte 2
  data_in[4]=send_byte_ns(0);               // Read data byte 1
  data_in[5]=send_byte_ns(0);               //Read data byte 2  
  ss_high();
  delay(2);
  write_reg_bit(0x07,6,1);                  //Clear Interrupt flag in STATUS reg of nRF very essential..because flag isn't automatically cleared when ISR is called
  ch1.writeMicroseconds(data_in[2]*4+1000); //one can make 10bytes packets on the tx node
  ch2.writeMicroseconds(data_in[3]*4+1000);
  ch3.writeMicroseconds(data_in[4]*4+1000);
  ch4.writeMicroseconds(data_in[5]*4+1000);
  //display_recv_data();
  //display_pwm();
}
