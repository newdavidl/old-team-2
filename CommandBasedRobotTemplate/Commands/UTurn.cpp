#include "UTurn.h"

UTurn::UTurn() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(tankDrive);
}

// Called just before this Command runs the first time
void UTurn::Initialize() {
	SetTimeout(5);
}

// Called repeatedly when this Command is scheduled to run
void UTurn::Execute() {
	tankDrive->tankDrive(-1,-0.1);
}

// Make this return true when this Command no longer needs to run execute()
bool UTurn::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void UTurn::End() {
	tankDrive->tankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UTurn::Interrupted() {
}
