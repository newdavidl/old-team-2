#include "FollowWall.h"

FollowWall::FollowWall() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(tankDrive);
}

// Called just before this Command runs the first time
void FollowWall::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void FollowWall::Execute() {
	if (tankDrive->getIRVoltage() > .8) {
		//too close, turn right
		tankDrive->tankDrive(0.5, 0.3);
	}
	else {
		//too far, turn left
		tankDrive->tankDrive(0.3, 0.5);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool FollowWall::IsFinished() {
	if(tankDrive->getIRVoltage() < 0.1){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void FollowWall::End() {
	tankDrive->tankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FollowWall::Interrupted() {
}
