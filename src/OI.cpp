// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DecreaseRPM.h"
#include "Commands/IncreaseRPM.h"
#include "Commands/IntakeCommand.h"
#include "Commands/ReturnOriginalRPM.h"
#include "Commands/ShooterCommand.h"
#include "Commands/UnjamCommand.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    joystick1.reset(new Joystick(0));
    
    returnOriginalRPM.reset(new JoystickButton(joystick1.get(), 2));
    returnOriginalRPM->WhileHeld(new ReturnOriginalRPM());
    decreaseRPMButton.reset(new JoystickButton(joystick1.get(), 5));
    decreaseRPMButton->WhenPressed(new DecreaseRPM());
    increaseRPMButton.reset(new JoystickButton(joystick1.get(), 6));
    increaseRPMButton->WhenPressed(new IncreaseRPM());
    unjamButton.reset(new JoystickButton(joystick1.get(), 3));
    unjamButton->WhileHeld(new UnjamCommand());
    intakeButton.reset(new JoystickButton(joystick1.get(), 1));
    intakeButton->WhileHeld(new IntakeCommand());
    shootButton.reset(new JoystickButton(joystick1.get(), 8));
    shootButton->WhileHeld(new ShooterCommand());

    // SmartDashboard Buttons
    SmartDashboard::PutData("ReturnOriginalRPM", new ReturnOriginalRPM());
    SmartDashboard::PutData("DecreaseRPM", new DecreaseRPM());
    SmartDashboard::PutData("IncreaseRPM", new IncreaseRPM());
    SmartDashboard::PutData("UnjamCommand", new UnjamCommand());
    SmartDashboard::PutData("IntakeCommand", new IntakeCommand());
    SmartDashboard::PutData("ShooterCommand", new ShooterCommand());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getjoystick1() {
   return joystick1;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
