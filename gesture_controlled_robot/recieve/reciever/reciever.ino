/*
 * The Reciever code for the Gesture Controlled Robot
 * Data is transmitter through the RF Reciever (433Mhz)
 * Author: Sudarshan S Harithas
 */

#include <VirtualWire.h>

// Declaration ofpins for motor control
int motrf=2;
int motrb=4;
int motlf=7;
int motlb=8;
int enable1=9;
int enable2=10;


void setup()
{
  
pinMode(motrf,OUTPUT);
pinMode(motlf,OUTPUT);
pinMode(motlb,OUTPUT);
pinMode(motrb,OUTPUT);
digitalWrite(enable1,HIGH);
digitalWrite(enable2,HIGH);


Serial.begin(9600);
vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(6);
vw_setup(4000);  // Bits per sec
pinMode(13, OUTPUT);
Serial.begin(9600);
vw_rx_start();       // Start the receiver PLL running

}
    void loop()
{
  
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      Serial.println("hello");
      
      if(buf[0]=='1'){

  
   digitalWrite(13,1);
   Serial.println("f");
     digitalWrite(motrf,HIGH);
      digitalWrite(motrb,LOW);
      digitalWrite(motlf,HIGH);
      digitalWrite(motlb,LOW);
      Serial.print("ok");
      }  
   if(buf[0]=='0'){
  digitalWrite(13,0);
  Serial.println("s");
       digitalWrite(motrf,LOW);
      digitalWrite(motrb,LOW);
      digitalWrite(motlf,LOW);
      digitalWrite(motlb,LOW); Serial.print("ok");
    }
     if(buf[0]=='2'){
  digitalWrite(13,0);
  Serial.println("b");
    digitalWrite(motrf,LOW);
      digitalWrite(motrb,HIGH);
      digitalWrite(motlf,LOW);
      digitalWrite(motlb,HIGH); Serial.print("ok");

}
  if(buf[0]=='3'){
  digitalWrite(13,0);
  Serial.println("l");
      digitalWrite(motrf,HIGH);
      digitalWrite(motrb,LOW);
      digitalWrite(motlf,LOW);
      digitalWrite(motlb,HIGH); Serial.print("ok");

}
  if(buf[0]=='4'){
  digitalWrite(13,0);
  Serial.println("r");
   digitalWrite(motrf,LOW);
      digitalWrite(motrb,HIGH);
      digitalWrite(motlf,HIGH);
      digitalWrite(motlb,LOW); Serial.print("ok");

}
}
}
