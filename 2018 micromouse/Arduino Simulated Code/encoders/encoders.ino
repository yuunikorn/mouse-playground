/* Read Quadrature Encoder
   Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.

   Sketch by max wolf / www.meso.net
   v. 0.1 - very basic functions - mw 20061220

*/

int encoder0PinA = 23;
int encoder0PinB = 22;

int encoder1PinA = 52;
int encoder1PinB = 53;

int encoder0Pos = 0;
int encoder1Pos = 0;
int encoder0PinALast, encoder1PinALast  = LOW;
int n,m = LOW;

void setup() {
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  Serial.begin (115200);
}

void loop() {
  
  n = digitalRead(encoder0PinA);
  m = digitalRead(encoder1PinA);
  
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }

  }

  
  if ((encoder1PinALast == LOW) && (m == HIGH)) {
    if (digitalRead(encoder1PinB) == LOW) {
      encoder1Pos--;
    } else {
      encoder1Pos++;
    }
  }
  
    Serial.print ("| Left: " ); 
    Serial.println (encoder1Pos);
    Serial.print ("Right: " );
    Serial.print (encoder0Pos);

    
  encoder0PinALast = n;
  encoder1PinALast = m;
}
