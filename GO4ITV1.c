#pragma config(Sensor, in2,    angle,          sensorPotentiometer)
#pragma config(Sensor, dgtl1,  lock,           sensorDigitalOut)
#pragma config(Sensor, dgtl2,  hope,           sensorDigitalOut)
#pragma config(Motor,  port2,           frontLeftMotor, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           frontRightMotor, tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           backLeftMotor, tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port5,           backRightMotor, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port9,           liftMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){

	//Defines the maximum value for the arm;
	//Value must be between 0 & 5000;
	//But 5000 only equals 260 degress
	int max = 2800;

	SensorValue[hope] = 1;

	//Deadzone contants
	int thresholdpos = 20;
	int chan1 = vexRT(Ch1);
	int chan2 = vexRT(Ch2);
	int chan3 = vexRT(Ch3);
	int chan4  = vexRT(Ch4);

	//Ch1 deadzone
	if(abs(vexRT[Ch1]) > thresholdpos)
		chan1 = vexRT(Ch1);
	else
		chan1 = 0;

	//Ch2 deadzone
	if(abs(vexRT[Ch2])> thresholdpos)
		chan2 = vexRT(Ch2);
	else
		chan2 = 0;


	//Ch3 deadzone
	if(abs(vexRT[Ch3])> thresholdpos)
		chan3 = vexRT(Ch3);
	else
		chan3 = 0;


	//Ch4 deadzone
	if(abs(vexRT[Ch4])> thresholdpos)
		chan4 = vexRT(Ch4);
	else
		chan4 = 0;

	//Basic and Crab Drive
	while (true){
		if((vexRT[Btn7D] == 1)) // && (vexRT[Btn7DXmtr2])
		{
			SensorValue[lock] = 0;
			wait1Msec(2000);
			SensorValue[lock] = 1;
		}
		if(vexRT[Btn8D] == 1)
			{
					SensorValue[lock] = 1;
			}


		if((SensorValue[angle] < max)&& (vexRT[Ch2Xmtr2] > 0))
		{
			motor[liftMotor] = vexRT[Ch2Xmtr2];
		}
		else if((SensorValue[angle] >= max)&& (vexRT[Ch2Xmtr2] > 0))
		{
			motor[liftMotor] = 0;
		}
		else
		{
			motor[liftMotor] = vexRT[Ch2Xmtr2];
		}

		//Robot movement
		motor[frontRightMotor] = vexRT[Ch4] + vexRT[Ch1] - vexRT[Ch3];
		motor[backRightMotor] =  vexRT[Ch4] - vexRT[Ch1] + vexRT[Ch3];
		motor[frontLeftMotor] = vexRT[Ch4] + vexRT[Ch1] + vexRT[Ch3];
		motor[backLeftMotor] =  vexRT[Ch4] - vexRT[Ch1] - vexRT[Ch3];


	}


}
