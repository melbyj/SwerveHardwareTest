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
	timeToRunTests = 20;
	currentTime = 0;
	testFileFLD.open("testDataFLD.csv");
	testFileFRD.open("testDataFRD.csv");
	testFileBLD.open("testDataBLD.csv");
	testFileBRD.open("testDataBRD.csv");
	testFileFLR.open("testDataFLR.csv");
	testFileFRR.open("testDataFRR.csv");
	testFileBLR.open("testDataBLR.csv");
	testFileBRR.open("testDataBRR.csv");
	testFileFLD << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileFRD << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBLD << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBRD << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileFLR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileFRR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBLR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBRR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";

	RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemFLRotTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemFRRotTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemBLRotTalon->Set(ControlMode::PercentOutput, .25);
	RobotMap::swerveSubsystemBRRotTalon->Set(ControlMode::PercentOutput, .25);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	currentTime = testTimer.Get();

	if(currentTime >= 5) {
		RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, .6666);
		RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, .6666);
	}

	if(currentTime >= 10) {
		RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, -.25);
		RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, -.25);
		RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, -.25);
		RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, -.25);
		RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, -.25);
		RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, -.25);
		RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, -.25);
		RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, -.25);
	}

	if(currentTime >= 15) {
		RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, -.6666);
		RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, -.6666);
		RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, -.6666);
		RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, -.6666);
		RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, -.6666);
		RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, -.6666);
		RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, -.6666);
		RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, -.6666);
	}

	if(currentTime <= timeToRunTests) {
		//Drive Talons
		testFileFLD << currentTime << ", " << RobotMap::swerveSubsystemFLDriveTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemFLDriveTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemFLDriveTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemFLDriveTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileFRD << currentTime << ", " << RobotMap::swerveSubsystemFRDriveTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemFRDriveTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemFRDriveTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemFRDriveTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileBLD << currentTime << ", " << RobotMap::swerveSubsystemBLDriveTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemBLDriveTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemBLDriveTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemBLDriveTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileBRD << currentTime << ", " << RobotMap::swerveSubsystemBRDriveTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemBRDriveTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemBRDriveTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemBRDriveTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		//Rotation Talons
		testFileFLR << currentTime << ", " << RobotMap::swerveSubsystemFLRotTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemFLRotTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemFLRotTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemFLRotTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileFRR << currentTime << ", " << RobotMap::swerveSubsystemFRRotTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemFRRotTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemFRRotTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemFRRotTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileBLR << currentTime << ", " << RobotMap::swerveSubsystemBLRotTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemBLRotTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemBLRotTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemBLRotTalon->GetSelectedSensorVelocity(0)
				   << "\n";

		testFileBRR << currentTime << ", " << RobotMap::swerveSubsystemBRRotTalon->GetMotorOutputVoltage()
				   << ", " << RobotMap::swerveSubsystemBRRotTalon->GetOutputCurrent()
				   << ", " << RobotMap::swerveSubsystemBRRotTalon->GetSelectedSensorPosition(0)
				   << ", " << RobotMap::swerveSubsystemBRRotTalon->GetSelectedSensorVelocity(0)
				   << "\n";
	}
	else {
		testFileFLD.close();
		testFileFRD.close();
		testFileBLD.close();
		testFileBRD.close();
		testFileFLR.close();
		testFileFRR.close();
		testFileBLR.close();
		testFileBRR.close();
	}
}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot);
