/*----------------------------------------------------------------------
Author: MD AKIB HOSEN KHAN
        B.Sc. in Information & Communication Technology
        Islamic University, Bangladesh.
________________________________________________________________________*/

char t;
 
void setup(){
  pinMode(3,OUTPUT);   //left motors forward
  pinMode(4,OUTPUT);   //left motors reverse
  
  pinMode(5,OUTPUT);   //right motors forward
  pinMode(6,OUTPUT);   //right motors reverse

  Serial.begin(9600);
 }
 
void loop(){
  if(Serial.available()){
     t = Serial.read();
     Serial.println(t);
  }
 
  if(t == 'F'){//move forward(all motors rotate in forward direction)
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(100);
  }
 
  else if(t == 'G'){      //move reverse (all motors rotate in reverse direction)
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    delay(100);
  }
 
  else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
   digitalWrite (3, LOW);
   digitalWrite (4, HIGH);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   delay (100);
  }
 
  else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    digitalWrite (3,HIGH);
    digitalWrite (4,LOW);
    digitalWrite (5,LOW);
    digitalWrite (6,HIGH);
    delay (100);
  }

  else if(t == 'S'){      //STOP (all motors stop)
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
  delay(60);
}
