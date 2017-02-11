// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CANTalon.h"
#include <CANSpeedController.h>
#include <SmartDashboard/SmartDashboard.h>

#include "ShooterSubsystem.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
	rpm1=2400;
	rpm2=2000;
	init1=rpm1;
	init2=rpm2;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    talonController = RobotMap::shooterSubsystemtalonController;
    talonController2 = RobotMap::shooterSubsystemtalonController2;
    feederMotor = RobotMap::shooterSubsystemfeederMotor;
    augerMotor = RobotMap::shooterSubsystemaugerMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void ShooterSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ShooterSubsystem::TurnOnThrottle(){
	talonController->SetControlMode(frc::CANSpeedController::ControlMode::kPercentVbus);
	talonController2->SetControlMode(frc::CANSpeedController::ControlMode::kPercentVbus);
	talonController->Set(.60);
	talonController2->Set(.60);
}

//call this once when the robot program is enabled to set the defaults
void ShooterSubsystem::BasicTabUpdateValues() {
	//std::cout << "BASIC SET VALUES \n";

	//GET SOME SETTINGS
	std::string cont1_p_str = frc::SmartDashboard::GetString("DB/String 0", "0.1"); //MOTOR 1 P
	std::cout<<"cont_p_str " << cont1_p_str;
	if (cont1_p_str == "") cont1_p_str = "0.1";

	std::string cont1_d_str = frc::SmartDashboard::GetString("DB/String 1", "5.5"); //MOTOR 1 D
	if (cont1_d_str == "") cont1_d_str = "5.5";

	std::string cont1_f_str = frc::SmartDashboard::GetString("DB/String 2", "0.03469"); //MOTOR 1 F
	if (cont1_f_str == "") cont1_f_str = "0.042";

	std::string cont1_rr_str = frc::SmartDashboard::GetString("DB/String 3", "2"); //MOTOR 1 RAMP RATE
	if (cont1_rr_str == "") cont1_rr_str = "2";

	std::string cont1_rpm_str = frc::SmartDashboard::GetString("DB/String 4", "2000"); //MOTOR 1 RPM
	if (cont1_rpm_str == "") cont1_rpm_str = "2400";

	std::string cont2_p_str = frc::SmartDashboard::GetString("DB/String 5", "0.1"); //MOTOR 2 P
	if (cont2_p_str == "") cont2_p_str = "0.1";

	std::string cont2_d_str = frc::SmartDashboard::GetString("DB/String 6", "5.5"); //MOTOR 2 D
	if (cont2_d_str == "") cont2_d_str = "5.5";

	std::string cont2_f_str = frc::SmartDashboard::GetString("DB/String 7", "0.03643"); //MOTOR 2 F
	if (cont2_f_str == "") cont2_f_str = "0.037";

	std::string cont2_rr_str = frc::SmartDashboard::GetString("DB/String 8", "2"); //MOTOR 2 RAMP RATE
	if (cont2_rr_str == "") cont2_rr_str = "2";

	std::string cont2_rpm_str = frc::SmartDashboard::GetString("DB/String 9", "2000"); //MOTOR 2 RPM
	if (cont2_rpm_str == "") cont2_rpm_str = "2000";

	//SET THEM BACK IN CASE WE DEFAULTED SO WE CAN SHOW THEM WHAT WE'RE USING
	frc::SmartDashboard::PutString("DB/String 0", cont1_p_str);
	frc::SmartDashboard::PutString("DB/String 1", cont1_d_str);
	frc::SmartDashboard::PutString("DB/String 2", cont1_f_str);
	frc::SmartDashboard::PutString("DB/String 3", cont1_rr_str);
	frc::SmartDashboard::PutString("DB/String 4", cont1_rpm_str);

	frc::SmartDashboard::PutString("DB/String 5", cont2_p_str);
	frc::SmartDashboard::PutString("DB/String 6", cont2_d_str);
	frc::SmartDashboard::PutString("DB/String 7", cont2_f_str);
	frc::SmartDashboard::PutString("DB/String 8", cont2_rr_str);
	frc::SmartDashboard::PutString("DB/String 9", cont2_rpm_str);

	//convert to doubles and set values on controller
	double p1, d1, f1, rr1;
	double p2, d2, f2, rr2;
	try
	{
		p1 = std::stod(cont1_p_str);
		d1 = std::stod(cont1_d_str);
		f1 = std::stod(cont1_f_str);
		rr1 = std::stod(cont1_rr_str);
		rpm1 = std::stod(cont1_rpm_str);
		init1 = rpm1;

		p2 = std::stod(cont2_p_str);
		d2 = std::stod(cont2_d_str);
		f2 = std::stod(cont2_f_str);
		rr2 = std::stod(cont2_rr_str);
		rpm2 = std::stod(cont2_rpm_str);
		init2 = rpm2;

		std::cout << "rpm values "<< rpm1 << " "<< rpm2 << "\n";
		std::cout << "p values "<< p1 << " "<< p2 << "\n";
		std::cout << "d values "<< d1 << " "<< d2 << "\n";
		std::cout << "f values "<< f1 << " "<< f2 << "\n";
		std::cout << "rr values "<< rr1 << " "<< rr2 << "\n";
		//put this after all the stod's so that 1 bad value kicks out and we
		//won't set anything
		talonController->SetPID(p1, 0, d1, f1);
		talonController->SetCloseLoopRampRate(rr1);
		talonController->Set(rpm1);

		talonController2->SetPID(p2, 0, d2, f2);
		talonController2->SetCloseLoopRampRate(rr2);
		talonController2->Set(rpm2);
	}
	catch (std::invalid_argument e)
	{
		std::cout << "Unable to parse basic tab values";
	}
	catch (std::out_of_range e)
	{
		std::cout << "Unable to parse basic tab values";
	}


}

void ShooterSubsystem::CustomTabUpdateValues() {
	std::cout << "custom SET VALUES \n";

	//GET SOME SETTINGS
	double rpm1 = frc::SmartDashboard::GetNumber("Shtr_M1_RPM", 0);
	double p1 = frc::SmartDashboard::GetNumber("Shtr_M1_p", 0);
	double i1 = frc::SmartDashboard::GetNumber("Shtr_M1_i", 0);
	double d1 = frc::SmartDashboard::GetNumber("Shtr_M1_d", 0);
	double f1 = frc::SmartDashboard::GetNumber("Shtr_M1_f", 0);
	double rr1 = frc::SmartDashboard::GetNumber("Shtr_M1_rr", 0);


	double rpm2 = frc::SmartDashboard::GetNumber("Shtr_M2_RPM", 0);
	double p2 = frc::SmartDashboard::GetNumber("Shtr_M2_p", 0);
	double i2 = frc::SmartDashboard::GetNumber("Shtr_M2_i", 0);
	double d2 = frc::SmartDashboard::GetNumber("Shtr_M2_d", 0);
	double f2 = frc::SmartDashboard::GetNumber("Shtr_M2_f", 0);
	double rr2 = frc::SmartDashboard::GetNumber("Shtr_M2_rr", 0);

		std::cout << "rpm values "<< rpm1 << " "<< rpm2 << "\n";
		std::cout << "p values "<< p1 << " "<< p2 << "\n";
		std::cout << "d values "<< d1 << " "<< d2 << "\n";
		std::cout << "f values "<< f1 << " "<< f2 << "\n";
		std::cout << "rr values "<< rr1 << " "<< rr2 << "\n";
		//put this after all the stod's so that 1 bad value kicks out and we
		//won't set anything
		talonController->SetPID(p1, i1, d1, f1);
		talonController->SetCloseLoopRampRate(rr1);
		talonController->Set(rpm1);

		talonController2->SetPID(p2, i2, d2, f2);
		talonController2->SetCloseLoopRampRate(rr2);
		talonController2->Set(rpm2);

}

void ShooterSubsystem::TurnOnRPMUsingBasicTab() {
	//TODO try disable to turn off, enable to turn on
	talonController->Enable();
	talonController2->Enable();

	talonController->SetControlMode(frc::CANSpeedController::ControlMode::kSpeed);
	talonController->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
	talonController->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	talonController->ConfigPeakOutputVoltage(+12.0f, -12.0f);
	talonController->SetSensorDirection(false);

	talonController2->SetControlMode(frc::CANSpeedController::ControlMode::kSpeed);
	talonController2->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
	talonController2->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	talonController2->ConfigPeakOutputVoltage(+12.0f, -12.0f);
	talonController2->SetSensorDirection(true);

	int izone = 0;
	int profile = 0;

	talonController->SelectProfileSlot(profile);
	talonController->SetIzone(izone);

	talonController2->SelectProfileSlot(profile);
	talonController2->SetIzone(izone);

	BasicTabUpdateValues();
}

void ShooterSubsystem::TurnOnRPM(){
	talonController->Enable();
	talonController2->Enable();
	//feederMotor->Enable();
	//augerMotor->();
	//talonController->SetSafetyEnabled(true);
	//talonController2->SetSafetyEnabled(true);
	//talonController->SetExpiration(1000);

	//talonController->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	//talonController2->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	//talonController2->ConfigEncoderCodesPerRev(1024);

	talonController->SetControlMode(frc::CANSpeedController::ControlMode::kSpeed);
	talonController->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
	talonController->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	talonController->ConfigPeakOutputVoltage(+12.0f, -12.0f);
	talonController->SetSensorDirection(false);

	talonController2->SetControlMode(frc::CANSpeedController::ControlMode::kSpeed);
	talonController2->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
	talonController2->ConfigNominalOutputVoltage(+0.0f, -0.0f);
	talonController2->ConfigPeakOutputVoltage(+12.0f, -12.0f);
	talonController2->SetSensorDirection(true);

	//we'll put optimized values here eventually
	double p = .1;
	double i = 0;
	double d = 5.5;
	double f = .042;
	double f2 = .037;
	int izone = 0;
	double ramprate = 2;
	int profile = 0;

	talonController->SelectProfileSlot(profile);
	talonController->SetPID(p, i, d, f);
	talonController->SetIzone(izone);
	talonController->SetCloseLoopRampRate(ramprate);
	talonController->Set(rpm1);

	talonController2->SelectProfileSlot(profile);
	talonController2->SetPID(p, i, d, f2);
	talonController2->SetIzone(izone);
	talonController2->SetCloseLoopRampRate(ramprate);
	talonController2->Set(rpm2);
}

void ShooterSubsystem::TurnOff(){
	//talonController->Set(0);
	//talonController2->Set(0);
	//feederMotor->Set(0);
	//augerMotor->Set(0);

	//TODO try disable instead of set(0) and see if that gives us a better turn off
	//NOTE, make sure to enable them in the "turnon" method then
	talonController->Disable();
	talonController2->Disable();
	feederMotor->Disable();
	augerMotor->Disable();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterSubsystem::PrintValues(){
	printf("RPM1=%f E1=%i RPM2=%f E2=%i \n",talonController->GetSpeed(),talonController->GetClosedLoopError(),talonController2->GetSpeed(),talonController2->GetClosedLoopError());
	double Encoder1 = frc::SmartDashboard::PutNumber("Shtr_M1_Encoder", talonController->GetSpeed());
	double Encoder2 = frc::SmartDashboard::PutNumber("Shtr_M2_Encoder", talonController2->GetSpeed());
}

void ShooterSubsystem::TurnOnFeederMotor(){
	feederMotor->Set(.4);
	augerMotor->Set(-.75);

}

void ShooterSubsystem::increaseRPM(){
	rpm1+=200;
	rpm2+=200;
}

void ShooterSubsystem::decreaseRPM(){
	rpm1+=200;
	rpm2+=200;
}

void ShooterSubsystem::returnOriginalRPM(){
	rpm1=init1;
	rpm2=init2;
}


