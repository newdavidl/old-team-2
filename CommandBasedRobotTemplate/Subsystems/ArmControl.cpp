#include "ArmControl.h"
#include "../Robotmap.h"

ArmControl::ArmControl() : Subsystem("ArmControl") {
	armServo = new Servo(ARM_CHANNEL);
}
    
void ArmControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	
}

void ArmControl::setArmVoltage(float voltage) {
	armServo->Set(voltage);
}

float ArmControl::getArmVoltage() {
	return armServo->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
