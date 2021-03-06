#include "main.h"

/**
 * Initializes a new drive object composed of four PantherMotors
 */
Drive initDrive(PantherMotor frontLeftMotor, PantherMotor frontRightMotor,
		PantherMotor rearLeftMotor, PantherMotor rearRightMotor)
{
	Drive newDrive = {frontLeftMotor, frontRightMotor,
			rearLeftMotor, rearRightMotor};

	return newDrive;
}

void tankDrive(Drive drive, int left, int right)
{
	int leftSpeed = limit(left, 127, -127);
	int rightSpeed = limit(right, 127, -127);

	setPantherMotor(drive.frontLeftMotor, leftSpeed);
	setPantherMotor(drive.rearLeftMotor, leftSpeed);
	setPantherMotor(drive.frontRightMotor, rightSpeed);
	setPantherMotor(drive.rearRightMotor, rightSpeed);
}

void arcadeDrive(Drive drive, int magnitude, int rotation)
{
	int left = limit(magnitude + rotation, 127, -127);
	int right = limit(magnitude - rotation, 127, -127);

	tankDrive(drive, left, right);
}
