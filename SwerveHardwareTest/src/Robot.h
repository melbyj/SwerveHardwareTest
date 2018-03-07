#ifndef _ROBOT_H
#define _ROBOT_H

#include "TimedRobot.h"
#include "Timer.h"
#include <fstream>

class Robot : public frc::TimedRobot {
public:
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
private:
	frc::Timer testTimer;
	double timeToRunTests;
	double currentTime;
	double currentSpeed;
	std::string m_OutputString;
	std::ofstream m_TestFile;
	
	/*std::ofstream testFileFLD;
	std::ofstream testFileFRD;
	std::ofstream testFileBLD;
	std::ofstream testFileBRD;
	std::ofstream testFileFLR;
	std::ofstream testFileFRR;
	std::ofstream testFileBLR;
	std::ofstream testFileBRR;*/
};

#endif
