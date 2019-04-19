#define center A1
//#define right 4
//#define left 3
int inputValCenter = 0;
int inputValLeft = 0;
int inputValRight = 0;

void setup() {
  pinMode(center, INPUT);
//  pinMode(center, INPUT);
//  pinMode(center, INPUT);
  Serial.begin(115200);

  Serial.println("IR sensors will run here");
  
  // put your setup code here, to run once:

}

void loop() {
    inputValCenter = analogRead(center);
 //   inputValLeft = analogRead(right);
 //   inputValRight = analogRead(left);


    Serial.println("\nCenter");
    Serial.println(inputValCenter);
  //  Serial.println("\nLeft");
 //   Serial.println(inputValLeft);
  //  Serial.println("\nRight");
//    Serial.println(inputValRight);

    delay(50);


}
