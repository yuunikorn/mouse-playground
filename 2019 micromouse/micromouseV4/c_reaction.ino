/* Functions for motors to move straight and turn
*
* Functions that can be called:
* --> Hardware Tester:
*
* --> Loop Functions:
*     reactivestraight(int timestep);
*          -Compensates straight detecting IR distance and setting motorspeed
*          -Takes singular reading of IR sensors when stopping
*          -Incorporates: a_ir, a_motor, b_turn
*          
* --> Modular Functions:
*
*
*/

int singleread = 150; //resets IR sensor memory
int ReadOnceLeft = singleread;
int ReadOnceRight = singleread;
int ReadOnceFront = singleread;

void reactivestraight(int timestep){
  int i = 0;

  while(i <= timestep){

    if (ReadOnceRight < 100 and ReadOnceLeft > 200){  //if right wall is available (open) and left wall exists
      TurnAngle(90 , 1);
      Stop();
      ReadOnceRight = singleread;
      i = 700;
    }

    else if(ReadOnceLeft < 100 and ReadOnceRight > 200){ //if left wall is available (open) and right wall exists
      TurnAngle(90 , 0);
      Stop();
      ReadOnceLeft = singleread;
      i = 700;
    }

    else if(ReadOnceLeft > 200 and ReadOnceFront > 200 and ReadOnceRight > 200){ //if surrounded by three walls
      TurnAngle(180 , 0);
      Stop();
      delay(1000);
      ReadOnceLeft = singleread;
      ReadOnceRight = singleread;
      ReadOnceFront = singleread;
      i = 700;
    }

    if (ReadOnceRight < 100 and ReadOnceFront > 200 and ReadOnceLeft < 100){  //if neither left/right eists, but center wall does
      Stop();

      int num = random(1, 3);
      if (num == 1){
        TurnAngle(90 , 1);
      }
      else{
        TurnAngle(90 , 0);
      }

      Stop();
      ReadOnceLeft = singleread;
      ReadOnceRight = singleread;
      ReadOnceFront = singleread;
      i = 700;
    }



    else{

      if (analogRead(SENSORFRONT) < IRrange){

        if(analogRead(SENSORRIGHT) < analogRead(SENSORLEFT) and analogRead(SENSORRIGHT) > 200){ //closer to the left | disregard open space on right
          Forward(85 , 70); //faster on the left (turns slightly right)
        }
        else if(analogRead(SENSORRIGHT) > analogRead(SENSORLEFT) and analogRead(SENSORLEFT) > 200 ){ //closer to the right | disregard open space on left
          Forward(70 , 85); //faster on the right (turns slightly left)
        }
        else{
          Forward(70 , 70);
        }
      }


      else{
        Stop();
        delay(1000);    //stops so sensors can be read
        ReadOnceLeft = analogRead(SENSORLEFT);
        ReadOnceRight = analogRead(SENSORRIGHT);
        ReadOnceFront = analogRead(SENSORFRONT);
        delay(10);
      }


      i++;
    }
  }
}
