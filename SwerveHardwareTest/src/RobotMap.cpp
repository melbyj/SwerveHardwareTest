#include "RobotMap.h"

std::shared_ptr<can::TalonSRX> RobotMap::swerveSubsystemFLDriveTalon;
std::shared_ptr<can::TalonSRX> RobotMap::swerveSubsystemFRDriveTalon;
std::shared_ptr<can::TalonSRX> RobotMap::swerveSubsystemBLDriveTalon;
std::shared_ptr<can::TalonSRX> RobotMap::swerveSubsystemBRDriveTalon;

std::shared_ptr<can::TalonSRX> RobotMap::swerveSubsystemFLRotTalon;
std::shared_ptr<can::TalonSRX> RobotMap::swerveSubsystemFRRotTalon;
std::shared_ptr<can::TalonSRX> RobotMap::swerveSubsystemBLRotTalon;
std::shared_ptr<can::TalonSRX> RobotMap::swerveSubsystemBRRotTalon;

std::shared_ptr<frc::PowerDistributionPanel> RobotMap::pdp;

void RobotMap::init() {
	swerveSubsystemFLDriveTalon.reset(new can::TalonSRX(2));
	swerveSubsystemFRDriveTalon.reset(new can::TalonSRX(3));
	swerveSubsystemBLDriveTalon.reset(new can::TalonSRX(4));
	swerveSubsystemBRDriveTalon.reset(new can::TalonSRX(5));

	swerveSubsystemFLRotTalon.reset(new can::TalonSRX(6));
	swerveSubsystemFRRotTalon.reset(new can::TalonSRX(7));
	swerveSubsystemBLRotTalon.reset(new can::TalonSRX(8));
	swerveSubsystemBRRotTalon.reset(new can::TalonSRX(9));

	pdp.reset(new frc::PowerDistributionPanel());

	swerveSubsystemFLDriveTalon->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);
	swerveSubsystemFRDriveTalon->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);
	swerveSubsystemBLDriveTalon->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);
	swerveSubsystemBRDriveTalon->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);

	swerveSubsystemFLDriveTalon->SetSelectedSensorPosition(0, 0, 10);
	swerveSubsystemFRDriveTalon->SetSelectedSensorPosition(0, 0, 10);
	swerveSubsystemBLDriveTalon->SetSelectedSensorPosition(0, 0, 10);
	swerveSubsystemBRDriveTalon->SetSelectedSensorPosition(0, 0, 10);

	swerveSubsystemFLDriveTalon->SetSensorPhase(false);
	swerveSubsystemFRDriveTalon->SetSensorPhase(false);
	swerveSubsystemBLDriveTalon->SetSensorPhase(false);
	swerveSubsystemBRDriveTalon->SetSensorPhase(false);

	swerveSubsystemFLDriveTalon->SetInverted(false);
	swerveSubsystemFRDriveTalon->SetInverted(false);
	swerveSubsystemBLDriveTalon->SetInverted(false);
	swerveSubsystemBRDriveTalon->SetInverted(false);

	swerveSubsystemFLDriveTalon->ConfigVoltageCompSaturation(12, 10);
	swerveSubsystemFRDriveTalon->ConfigVoltageCompSaturation(12, 10);
	swerveSubsystemBLDriveTalon->ConfigVoltageCompSaturation(12, 10);
	swerveSubsystemBRDriveTalon->ConfigVoltageCompSaturation(12, 10);

	swerveSubsystemFLDriveTalon->EnableVoltageCompensation(true);
	swerveSubsystemFRDriveTalon->EnableVoltageCompensation(true);
	swerveSubsystemBLDriveTalon->EnableVoltageCompensation(true);
	swerveSubsystemBRDriveTalon->EnableVoltageCompensation(true);

}
