/*
 * The Transmitter code for the Gesture Controlled Robot
 * Data is transmitter through the RF transmitter (433Mhz)
 * Author: Sudarshan S Harithas
 */


#include <VirtualWire.h>
char *controller;  // The data to be transmitted
int xPin=A3;    //X axis input from Accelerometer
int yPin=A2;  //Y axis input from Accelerometer
long x;         //Variabe for storing X coordinates
long y;         //Variabe for storing Y coordinates


void setup() {

Serial.begin(9600);
pinMode(xPin,INPUT);
pinMode(yPin,INPUT);
pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); 
vw_set_tx_pin(12);
vw_setup(4000); 

}

void loop() {
 
x = analogRead(xPin); //Reads X coordinates
y = analogRead(yPin); //Reads Y coordinates
if(x<340)      // Change the value for adjusting sensitivity  
      forward();
else if(x>400) // Change the value for adjusting sensitivity
      backward();
else if(y>400) // Change the value for adjusting sensitivity
      right();
else if(y<340) // Change the value for adjusting sensitivity
      left();
else
      stop_();
}

/*
 * Function Name : stop
 * Functionality : to transmit 0 to stop the robot
 */

void stop_()
{
  
controller="0";
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
Serial.println("stop");

}

/*
 * Function Name : forward
 * Functionality : to transmit 1 to move the robot forward
 */

void forward()
{
  
controller="1";
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
Serial.println("forward");
}


/*
 * Function Name : backward
 * Functionality : to transmit 2 to move the robot backward
 */
 
void backward()
{
controller="2";
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
Serial.println("backward");
}

/*
 * Function Name : left
 * Functionality : to transmit 3 to move the robot left
 */

void left()
{
controller="3";
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
Serial.println("left");
}



/*
 * Function Name : right
 * Functionality : to transmit 4 to move the robot right
 */


void right()
{
controller="4";
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
Serial.println("right");
}

