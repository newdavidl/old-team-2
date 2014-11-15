#include "OI.h"
#include "Commands/Drive2Secs.h"
#include "Commands/RotateCW90.h"
#include "Commands/RotateCCW90.h"
#include "Commands/TurnAndDrive.h"
#include "Commands/UTurn.h"


//#include "Commands/TurnAndDrive.h"

OI::OI() {
	left = new Joystick(JOYSTICK_1);
	right = new Joystick(JOYSTICK_2);
	Button* button1 = new JoystickButton(left, 5);
	Button* button2 = new JoystickButton(left, 6);
	Button*	button3 = new JoystickButton(left, 7);
	Button* button4 = new JoystickButton(left, 8);
	Button* button5 = new JoystickButton(left, 9);
	button1->WhenPressed(new RotateCW90());
	button2->WhenPressed(new RotateCCW90());
	button3->WhenPressed(new Drive2Secs());
	button4->WhenPressed(new TurnAndDrive());
	button5->WhenPressed(new UTurn());
	ir = new AnalogChannel(1,IR_CHANNEL);
}

float OI::getLeftY(){
	return left->GetY();
}

float OI::getRightY(){
	return right->GetY();
}
