#ifndef ARMCONTROL_H
#define ARMCONTROL_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author David
 */
class ArmControl: public Subsystem {
private:
	Servo *armServo;
	
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ArmControl();
	void InitDefaultCommand();
	void setArmVoltage(float voltage);
	float getArmVoltage();
//	void setArmAngle(float angle);
//	float getArmAngle();
};

#endif
