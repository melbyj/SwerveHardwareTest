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
	
	m_OutputString = "";
		
	testTimer.Reset();
	testTimer.Start();
	timeToRunTests = 20;
	currentTime = 0;
	currentSpeed = .25;
	/*testFileFLD.open("testDataFLD.csv");
	testFileFRD.open("testDataFRD.csv");
	testFileBLD.open("testDataBLD.csv");
	testFileBRD.open("testDataBRD.csv");
	testFileFLR.open("testDataFLR.csv");
	testFileFRR.open("testDataFRR.csv");
	testFileBLR.open("testDataBLR.csv");
	testFileBRR.open("testDataBRR.csv");*/
	
	m_OutputString << "Time, FLD CV, FLD TC, FLD EP, FLD EV";
	m_OutputString << ", FRD CV, FRD TC, FRD EP, FRD EV";
	m_OutputString << ", BLD CV, BLD TC, BLD EP, BLD EV";
	m_OutputString << ", BRD CV, BRD TC, BRD EP, BRD EV";
	m_OutputString << ", FLR CV, FLR TC, FLR EP, FLR EV";
	m_OutputString << ", FRR CV, FRR TC, FRR EP, FRR EV";
	m_OutputString << ", BLR CV, BLR TC, BLR EP, BLR EV";
	m_OutputString << ", BRR CV, BRR TC, BRR EP, BRR EV\n";
	
	/*testFileFLD << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileFRD << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBLD << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBRD << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileFLR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileFRR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBLR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";
	testFileBRR << "Time, Commanded Voltage, Talon Current, Encoder Position, Encoder Velocity" << "\n";*/


}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	currentTime = testTimer.Get();

	if(currentTime >= 5) {
		currentSpeed = .6666;
	}

	if(currentTime >= 10) {
		currentSpeed = -.25;
	}

	if(currentTime >= 15) {
		currentSpeed = -.6666;
	}

	SetSpeed(currentSpeed);
	/*RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, currentSpeed);
	RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, currentSpeed);
	RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, currentSpeed);
	RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, currentSpeed);
	RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, currentSpeed);
	RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, currentSpeed);
	RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, currentSpeed);
	RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, currentSpeed);*/

	if(currentTime <= timeToRunTests) {
		//Drive Talons
		m_OutputString	+=currentTime
			
				+ ", " + RobotMap::swerveSubsystemFLDriveTalon->GetMotorOutputVoltage()
				+ ", " + RobotMap::swerveSubsystemFLDriveTalon->GetOutputCurrent()
				+ ", " + RobotMap::swerveSubsystemFLDriveTalon->GetSelectedSensorPosition(0)
				+ ", " + RobotMap::swerveSubsystemFLDriveTalon->GetSelectedSensorVelocity(0)
			
				+ ", " + RobotMap::swerveSubsystemFRDriveTalon->GetMotorOutputVoltage()
				+ ", " + RobotMap::swerveSubsystemFRDriveTalon->GetOutputCurrent()
				+ ", " + RobotMap::swerveSubsystemFRDriveTalon->GetSelectedSensorPosition(0)
				+ ", " + RobotMap::swerveSubsystemFRDriveTalon->GetSelectedSensorVelocity(0)
	
			 	+ ", " + RobotMap::swerveSubsystemBLDriveTalon->GetMotorOutputVoltage()
				+ ", " + RobotMap::swerveSubsystemBLDriveTalon->GetOutputCurrent()
				+ ", " + RobotMap::swerveSubsystemBLDriveTalon->GetSelectedSensorPosition(0)
				+ ", " + RobotMap::swerveSubsystemBLDriveTalon->GetSelectedSensorVelocity(0)

				+ ", " + RobotMap::swerveSubsystemBRDriveTalon->GetMotorOutputVoltage()
				+ ", " + RobotMap::swerveSubsystemBRDriveTalon->GetOutputCurrent()
				+ ", " + RobotMap::swerveSubsystemBRDriveTalon->GetSelectedSensorPosition(0)
				+ ", " + RobotMap::swerveSubsystemBRDriveTalon->GetSelectedSensorVelocity(0)

		//Rotation Talons
				+ ", " + RobotMap::swerveSubsystemFLRotTalon->GetMotorOutputVoltage()
				+ ", " + RobotMap::swerveSubsystemFLRotTalon->GetOutputCurrent()
				+ ", " + RobotMap::swerveSubsystemFLRotTalon->GetSelectedSensorPosition(0)
				+ ", " + RobotMap::swerveSubsystemFLRotTalon->GetSelectedSensorVelocity(0)

				+ ", " + RobotMap::swerveSubsystemFRRotTalon->GetMotorOutputVoltage()
				+ ", " + RobotMap::swerveSubsystemFRRotTalon->GetOutputCurrent()
				+ ", " + RobotMap::swerveSubsystemFRRotTalon->GetSelectedSensorPosition(0)
				+ ", " + RobotMap::swerveSubsystemFRRotTalon->GetSelectedSensorVelocity(0)

				+ ", " + RobotMap::swerveSubsystemBLRotTalon->GetMotorOutputVoltage()
				+ ", " + RobotMap::swerveSubsystemBLRotTalon->GetOutputCurrent()
				+ ", " + RobotMap::swerveSubsystemBLRotTalon->GetSelectedSensorPosition(0)
				+ ", " + RobotMap::swerveSubsystemBLRotTalon->GetSelectedSensorVelocity(0)

				+ ", " + RobotMap::swerveSubsystemBRRotTalon->GetMotorOutputVoltage()
				+ ", " + RobotMap::swerveSubsystemBRRotTalon->GetOutputCurrent()
				+ ", " + RobotMap::swerveSubsystemBRRotTalon->GetSelectedSensorPosition(0)
				+ ", " + RobotMap::swerveSubsystemBRRotTalon->GetSelectedSensorVelocity(0)
				+ "\n";
	}
	else {
		SetSpeed(0);
		
		m_TestFile.open("/home/lvuser/TestFile.csv");
		m_TestFile << m_OutputString;
		m_TestFile.flush();
		m_TestFile.close();
		
		/*testFileFLD.close();
		testFileFRD.close();
		testFileBLD.close();
		testFileBRD.close();
		testFileFLR.close();
		testFileFRR.close();
		testFileBLR.close();
		testFileBRR.close();*/
	}
}

void Robot::TestPeriodic() {

}

void Robot::SetSpeed(double tempSpeeed)
{
	RobotMap::swerveSubsystemFLDriveTalon->Set(ControlMode::PercentOutput, tempSpeeed);
	RobotMap::swerveSubsystemFRDriveTalon->Set(ControlMode::PercentOutput, tempSpeeed);
	RobotMap::swerveSubsystemBLDriveTalon->Set(ControlMode::PercentOutput, tempSpeeed);
	RobotMap::swerveSubsystemBRDriveTalon->Set(ControlMode::PercentOutput, tempSpeeed);
	RobotMap::swerveSubsystemFLRotTalon->Set(ControlMode::PercentOutput, tempSpeeed);
	RobotMap::swerveSubsystemFRRotTalon->Set(ControlMode::PercentOutput, tempSpeeed);
	RobotMap::swerveSubsystemBLRotTalon->Set(ControlMode::PercentOutput, tempSpeeed);
	RobotMap::swerveSubsystemBRRotTalon->Set(ControlMode::PercentOutput, tempSpeeed);
}

START_ROBOT_CLASS(Robot);
