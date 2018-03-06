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
	std::ofstream testFileFL;
	std::ofstream testFileFR;
	std::ofstream testFileBL;
	std::ofstream testFileBR;
};

#endif
