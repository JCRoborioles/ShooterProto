// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ShooterCommand.h"
#include <chrono>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ShooterCommand::ShooterCommand(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooterSubsystem.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ShooterCommand::Initialize() {
	//printf("initialize");
	std::cout << "initialize\n";

	//this is the method we'll call for competition after we find the optimized values
	//Robot::shooterSubsystem->TurnOnRPM();

	//turn the shooter motors on with this method to read from the basic tab
	Robot::shooterSubsystem->TurnOnRPM();

	//TODO: probably need to stagger the start of the feeder motor
	//to give the shooter motors time to start up... but just turn it on for now
	//There are various ways to try this, we could:
	//
	//     1) specify the # of execute iterations to wait until we turn it on and just
	//        check the count of "executeCount" and turn on the motor when it gets to a
	//        certain spot... NOTE,
	//
	//     2) #include <chrono>
	//        -- actually get the current system timestamp using the below "getTimestamp" method
	//        -- compare the timestamp of when "initialize" was called in each "execute" call
	//        until it is time to turn the feeder motor on
	//        -- we only want to turn it on once so need to keep track of that too
	//

	//Robot::shooterSubsystem->TurnOnFeederMotor();

	//reset the count
	executeCount = 0;
}

std::chrono::milliseconds getTimestamp() {
	using namespace std::chrono;
	milliseconds ms = duration_cast< milliseconds >(
	    system_clock::now().time_since_epoch()
	);
	return ms;
}

// Called repeatedly when this Command is scheduled to run
void ShooterCommand::Execute() {
	executeCount++;

	//TODO: adjust this value to alter how often the speed is outputed to the console
	//I *THINK* execute is called every 20 milliseconds, so "10" outputs it every 200ms or 5 times a second
	if (executeCount % 10) {
		Robot::shooterSubsystem->PrintValues();

		//TODO: do we need to reset so the # doesn't get too high? not if we're using
		//the count for anything else
		//executeCount = 0;
	}
	//start auger and feeder motors with delay
	if(executeCount==25)
	{
		//	not tested
		Robot::shooterSubsystem->TurnOnFeederMotor();
	}
	//resets execute value -- don't make it <= above
	if(executeCount==100)
	{
		executeCount=26;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterCommand::IsFinished() {
   //printf("isFinished");
	//std::cout << "isFinished";
	return false;
}

// Called once after isFinished returns true
void ShooterCommand::End() {
	std::cout << "End\n";
	//printf("End");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterCommand::Interrupted() {
	Robot::shooterSubsystem->TurnOff();
	printf("interrupted\n");
}
