//Tevon Walker - Low Level Motor/Steering Control firmware

#include <Servo.h>

Servo drive; //Servo Object for DC Motor
Servo steer;//Servo Object for steering Servo

#define LEFT 40 //lower bound for servo
#define RIGHT 140 //upper bound for servo
#define CENTER 90 
#define DAMPENING_OFFSET 25 // value for softening turns
#define STOP 96 // value for stopping DC Motor
#define SPEED_ONE 80 // speed level one
#define SPEED_TWO 70 // speed level two
#define SPEED_THREE 50 // speed level there
#define REVERSE 110 //reverse
#define STEER 6 // pin 6 ~PWM
#define DRIVE 5 // pin 5 ~PWM

void setup() {
  drive.attach(DRIVE); // assign motor to pin 5
  steer.attach(STEER); // assign steer servo to pin 6
  Serial.begin(9600); //open serial port w/ baudrate 9600
  Serial.setTimeout(5);
}




void loop() {

  if (Serial.available()) {
    int num = Serial.parseInt();
    
    switch (num){
      case 1000:{ //full left
        steer.write(LEFT);
        break;
        }
      case 2000:{ //gradual left
        steer.write(LEFT+DAMPENING_OFFSET);
        break;
      }
     case 3000:{ //center
      steer.write(CENTER);
      break;
     }
     case 4000:{ //gradual right
      steer.write(RIGHT-DAMPENING_OFFSET);
      break;
     }
     case 5000:{ //full right
      steer.write(RIGHT);
      break;
     }

     case 0:{ //stop vehicle
      drive.write(STOP);
      steer.write(CENTER);
      break;
     }
     case 1:{ //speed 1
      drive.write(SPEED_ONE);
      break;
     }
     case 2:{ //speed 2
      drive.write(SPEED_TWO);
      break;
     }
     case 3:{ //speed 3
      drive.write(SPEED_THREE);
      break;
     }
     case 4:{ // reverse
      drive.write(REVERSE);
      steer.write(CENTER);
      break;
     }
    }
    
  }

}
