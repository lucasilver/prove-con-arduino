#define LED 12 // impostiamo la variabile LED sul pin digitale 12
int val = 0; // usiamo la variabile val per salvare i valori provenienti da tastiera
int stato = 0; // usiamo la variabile stato per salvare lo stato in cui si trova il led. 0 = spento, 1 = acceso
int i=0;//variabile contatore

void setup() {
 pinMode(LED, OUTPUT); // impostiamo il pin del led (12) come output
 Serial.begin(9600);
}

void loop() {
 val = Serial.read(); // leggiamo il valore da tastiera e lo salviamo

 // controlliamo che l'input sia la lettera a
 // e, se lo è, cambiamo lo stato del led
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
   }
}
