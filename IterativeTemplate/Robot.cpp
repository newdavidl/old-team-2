#include "Robot.hpp"

Robot::Robot()
{
	drive = new RobotDrive(new Jaguar(1), new Jaguar(2), new Jaguar (3), new Jaguar(4));
	stick = new Joystick(1);
}


Robot::~Robot()
{
	delete drive;
	delete stick;
}

void Robot::TeleopPeriodic()
{
	drive->ArcadeDrive(stick->GetY(), - stick->GetZ());
}

