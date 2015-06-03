

#define LED 12 // impostiamo la variabile LED sul pin digitale 12
int val = 0; // usiamo la variabile val per salvare i valori provenienti da tastiera
int stato = 0; // usiamo la variabile stato per salvare lo stato in cui si trova il led. 0 = spento, 1 = acceso
int i=0;//variabile contatore

void setup() {
 pinMode(LED, OUTPUT); // impostiamo il pin del led (12) come output
 pinMode(3, OUTPUT);//buzzer
 Serial.begin(9600);
}

void loop() {
 val = Serial.read(); // leggiamo il valore da tastiera e lo salviamo

 // controlliamo che l'input sia la lettera a
 // e, se lo è, cambiamo lo stato del led
 
 // aggiungi
 switch(val)
   {
     case 'a':
     digitalWrite(LED, HIGH);
     break;
     
     case 'b':
     digitalWrite(LED, LOW);
     break;
     
     case 'c':
     for(i=0;i<5;i++)
     {
       digitalWrite(LED, HIGH);
       delay(600);
       digitalWrite(LED, LOW);
       delay(600);
     }
     break;
     
     case 'd':
      buzz(3,440,12);
      buzz(3,494,6);
      buzz(3,523,12);
     break;
     
     case 'e':
      buzz(3,523,12);
      buzz(3,494,6);
      buzz(3,440,12);
     break;
   }
}


void buzz(int targetPin, long frequency, long length) {
  
  long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to 
  //// get the total number of cycles to produce
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  

}
