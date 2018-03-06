#include "Robot.h"
#include "RobotMap.h"
#include <iostream>

void Robot::RobotInit() {
	std::cout << "Robot is starting!" << std::endl;
	RobotMap::init();
}

void Robot::DisabledInit() {
	std::cout << "Disabled!" << std::endl;
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	std::cout << "Autonomous Init!" << std::endl;
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	std::cout << "Teleop Init!" << std::endl;

	testTimer.Reset();
	testTimer.Start();
	timeToRunTests = 10;
	currentTime = 0;
	testFileFL.open("testDataFL.csv");
	testFileFR.open("testDataFR.csv");
	testFileBL.open("testDataBL.csv");
	testFileBR.open("testDataBR.csv");
	testFileFL << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileFR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBL << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";

	RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, .25);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	currentTime = testTimer.Get();

	if(currentTime >= 5) {
		RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, .6666);
	}

	if(currentTime <= timeToRunTests) {
		testFileFL << currentTime << ", " << RobotMap::swerveSubsystemFLDriveTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemFLDriveTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemFLDriveTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemFLDriveTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileFR << currentTime << ", " << RobotMap::swerveSubsystemFRDriveTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemFRDriveTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemFRDriveTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemFRDriveTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileBL << currentTime << ", " << RobotMap::swerveSubsystemBLDriveTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemBLDriveTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemBLDriveTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemBLDriveTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileBR << currentTime << ", " << RobotMap::swerveSubsystemBRDriveTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemBRDriveTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemBRDriveTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemBRDriveTalon->GetSelectedSensorVelocity(0)
				   << "\n";
	}
	else {
		testFileFL.close();
		testFileFR.close();
		testFileBL.close();
		testFileBR.close();
	}
}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot);
