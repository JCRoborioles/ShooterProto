// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "CANTalon.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemtalonController;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemtalonController2;
std::shared_ptr<SpeedController> RobotMap::shooterSubsystemfeederMotor;
std::shared_ptr<SpeedController> RobotMap::shooterSubsystemaugerMotor;
std::shared_ptr<SpeedController> RobotMap::intakeSubsystemintakeMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    shooterSubsystemtalonController.reset(new CANTalon(5));
    lw->AddActuator("ShooterSubsystem", "talonController", shooterSubsystemtalonController);
    
    shooterSubsystemtalonController2.reset(new CANTalon(6));
    lw->AddActuator("ShooterSubsystem", "talonController2", shooterSubsystemtalonController2);
    
    shooterSubsystemfeederMotor.reset(new Talon(1));
    lw->AddActuator("ShooterSubsystem", "feederMotor", std::static_pointer_cast<Talon>(shooterSubsystemfeederMotor));
    
    shooterSubsystemaugerMotor.reset(new Talon(0));
    lw->AddActuator("ShooterSubsystem", "augerMotor", std::static_pointer_cast<Talon>(shooterSubsystemaugerMotor));
    
    intakeSubsystemintakeMotor.reset(new Talon(2));
    lw->AddActuator("IntakeSubsystem", "intakeMotor", std::static_pointer_cast<Talon>(intakeSubsystemintakeMotor));
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
