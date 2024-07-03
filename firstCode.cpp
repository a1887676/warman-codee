#include <AccelStepper.h>

//CHECK WIRING CORRECTLY, eg. for motor 1: step pin is 3 and direction pin is 2
#define STEP_PIN1 3
#define DIR_PIN1 2
#define STEP_PIN2 5
#define DIR_PIN2 4
#define STEP_PIN3 7
#define DIR_PIN3 6
#define STEP_PIN4 9
#define DIR_PIN4 8

#define STEPS_PER_REVOLUTION 200

AccelStepper stepper1(AccelStepper::DRIVER, STEP_PIN1, DIR_PIN1);
AccelStepper stepper2(AccelStepper::DRIVER, STEP_PIN2, DIR_PIN2);
AccelStepper stepper3(AccelStepper::DRIVER, STEP_PIN3, DIR_PIN3);
AccelStepper stepper4(AccelStepper::DRIVER, STEP_PIN4, DIR_PIN4);

void setup() {

  stepper1.setMaxSpeed(150); 
  stepper1.setAcceleration(50); 
  stepper2.setMaxSpeed(150);
  stepper2.setAcceleration(50); 
  stepper3.setMaxSpeed(150);
  stepper3.setAcceleration(50); 
  stepper4.setMaxSpeed(150); 
  stepper4.setAcceleration(50); 
  
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  stepper4.setCurrentPosition(0);
}

void loop() {

  moveToDegree(180);
  delay(2000); 
  
  
  moveToDegree(0);
  delay(2000); 
}


void moveToDegree(float degree) {
  
  long targetPosition = map(degree, 0, 360, 0, STEPS_PER_REVOLUTION);
  
 
  stepper1.moveTo(targetPosition);
  stepper2.moveTo(targetPosition);
  stepper3.moveTo(targetPosition);
  stepper4.moveTo(targetPosition);
  
  
  while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 || stepper3.distanceToGo() != 0 || stepper4.distanceToGo() != 0) {
    stepper1.run();
    stepper2.run();
    stepper3.run();
    stepper4.run();
  }
}



// TEST THIS FUNCTION ONLY. You will need to call the function in order to run it as this is only the function definition
void runForward(unsigned long runTime) {

int RunSpeed = 50; //USE THIS TO CHANGE SPEED THAT MOTOR RUNS AT (max speed is 150 as set by "setMaxSpeed" class function)
stepper1.setSpeed(RunSpeed);
stepper2.setSpeed(RunSpeed);
stepper3.setSpeed(RunSpeed);
stepper4.setSpeed(RunSpeed);

unsigned long startTime = millis();

while(millis()-startTime<runTime) {
    stepper1.runSpeed();
    stepper2.runSpeed();
    stepper3.runSpeed();
    stepper4.runSpeed();

}

stepper1.setSpeed(0);
stepper2.setSpeed(0);
stepper3.setSpeed(0);
stepper4.setSpeed(0);

}