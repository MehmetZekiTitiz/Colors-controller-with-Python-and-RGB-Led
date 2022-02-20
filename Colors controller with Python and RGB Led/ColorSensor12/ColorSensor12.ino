
  int signal0=5;
  int signal1=6;
  int signal2=7;
  int signal3=8;
  int output=9; 
  int RGB_bluepin=11;
  int RGB_greenpin=12;
  int RGB_redpin=13;
  int Red,Green,Blue;
 
void setup() {
    
   pinMode(signal0,OUTPUT);
   pinMode(signal1,OUTPUT);
   pinMode(signal2,OUTPUT);
   pinMode(signal3,OUTPUT);
   pinMode(output,INPUT); 
     
   pinMode(RGB_redpin,OUTPUT);
   pinMode(RGB_bluepin,OUTPUT);
   pinMode(RGB_greenpin,OUTPUT);

    //Frequency value %20
   digitalWrite(signal0,HIGH);
   digitalWrite(signal1,LOW);

   Serial.begin(9600);

}

    void control()
    {
        //Red rengi belirlicez.
         //S2 ve S3 low
      digitalWrite(signal2,LOW);
      digitalWrite(signal3,LOW);
      Red = pulseIn(output,LOW);

      //Serial.print("Red color:");
      //Serial.print(Red);
      delay(50);
      

         //Green rengi belirlicez.
         //S2 ve S3 HIGH
      digitalWrite(signal2,HIGH);
      digitalWrite(signal3,HIGH);
      Green = pulseIn(output,LOW);

      //Serial.print("Green color:");
      //Serial.print(Green);
      delay(50);

          //Blue rengi belirlicez.
         //S2= low ve S3 HIGH
      digitalWrite(signal2,LOW);
      digitalWrite(signal3,HIGH);
      Blue = pulseIn(output,LOW);

      //Serial.print("Blue color:");
      //Serial.println(Blue);
      delay(500);
       
        
    }

     void controller_completed()
    {
        //Red rengi belirlicez.
         //S2 ve S3 low
      digitalWrite(signal2,LOW);
      digitalWrite(signal3,LOW);
      Red = pulseIn(output,LOW);
      Red=map(Red,80,220,0,100);
     // Serial.print("Red color:");
      //Serial.print(Red);
      delay(50);
      

         //Green rengi belirlicez.
         //S2 ve S3 HIGH
      digitalWrite(signal2,HIGH);
      digitalWrite(signal3,HIGH);
      Green = pulseIn(output,LOW);
      Green =map(Green,76,212,0,100);
      //Serial.print("Green color:");
      //Serial.print(Green);
      delay(50);

          //Blue rengi belirlicez.
         //S2= low ve S3 HIGH
      digitalWrite(signal2,LOW);
      digitalWrite(signal3,HIGH);
      Blue = pulseIn(output,LOW);
      Blue= map(Blue,55,159,0,100);
     // Serial.print("Blue color:");
      //Serial.println(Blue);
      delay(500);
       
        
    }
     void choose_color()
      {
        if(Red<Blue and Red<Green )
        {
          
          Serial.println("r");
           digitalWrite(RGB_bluepin,HIGH);
          digitalWrite(RGB_redpin,LOW);
          digitalWrite(RGB_greenpin,HIGH);
          
        }
        else if(Green<Red and Green<Blue)
        { 
            
          Serial.print("g");
           digitalWrite(RGB_bluepin,HIGH);
          digitalWrite(RGB_redpin,HIGH);
          digitalWrite(RGB_greenpin,LOW);

        }
        
         else if(Blue<Red and Blue<Green)
        {
          
          Serial.println("b");
          digitalWrite(RGB_bluepin,LOW);
          digitalWrite(RGB_redpin,HIGH);
          digitalWrite(RGB_greenpin,HIGH);
        }
          
          else
        {
          Serial.println("f");
          
        }
      }

void loop() {

     

     controller_completed();
     choose_color(); 
      

}
