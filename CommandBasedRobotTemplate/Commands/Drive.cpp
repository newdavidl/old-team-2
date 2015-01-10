#include "Drive.h"
#include <math.h>

double a = 0.55, b = 0.25, activate_val = 0.2;
double leftY, rightY;

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(tankDrive);
	Requires(armControl);
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	leftY = oi->getLeftY();
	SmartDashboard::PutNumber("Original LeftY ", leftY);
		rightY = oi->getRightY();
		SmartDashboard::PutNumber("Original RightY", rightY);
		
		
		// leftYCode
		double x = leftY;
		if(x > activate_val)
		{
			leftY = b + (1-b)*(a * (pow(x,3)) + (1-a)*x);
		}
		
		else if(x < activate_val)
		{
			leftY = -b + (1-b)*(a*(pow(x,3)) + (1-a)*x);
		}
		
		else {
			leftY = 0;
		}
		
		// rightYCode
		x = rightY;
		if(x > activate_val)
			{
				rightY = b + (1-b)*(a * (pow(x,3)) + (1-a)*x);
			}
			
			else if(x < activate_val)
			{
				rightY = -b + (1-b)*(a*(pow(x,3)) + (1-a)*x);
			}
			
			else {
				rightY = 0;
			}
		
		// execution
		SmartDashboard::PutNumber("New LeftY", leftY);
		SmartDashboard::PutNumber("New RightY", rightY);
		tankDrive->tankDrive(leftY, rightY);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {
}
