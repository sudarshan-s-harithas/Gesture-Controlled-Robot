
void setup() {

// Declaring  the pins to be connected to the motor driver 

pinMode(5,OUTPUT);  // 5 is the Right Motor Forward pin
pinMode(6,OUTPUT);  // 6 is the Right Motor Backward pin
pinMode(7,OUTPUT);  // 7 is the Left Motor Forward pin
pinMode(8,OUTPUT);  // 7 is the Left Motor Backward pin

// Initilizing  the pins to low    
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);

Serial.begni(9600);

}

void loop() {
// Move forward for 20 seconds
Serial.println("Forward");
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);

delay(20000);


// Move backward for 20 seconds

Serial.println("B");
digitalWrite(5,LOW);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);  

delay(20000);

}