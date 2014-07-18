#include "filter.h"
using namespace std;

/*
* A complementary filter for the readings from the accelerometer and gyroscope.
* Uses high and low pass filtering from the accelerometer and gyroscope in order to
* get better angles. Angle accuracy is extremely important as a slight change in angle
* will manifest as extremely large error in positional tracking. 
*
* @param fusion
*	Fusion objected attached to sensor devices
* @return filteredValue
*	Filtered pair of the acceleration the filtered angle was calculated at.
*	Acceleration is needed in order to maintain angle with corrected accelerometer
*	readings.
*/
pair<Vector3f, float> ComFilter(pair<EulerAngles, Vector3f> readings)
{
	//Constants
	double low = 9.8;
	double high = 19.6;
	float gyroWeight = .98;
	float accWeight = .02;

	// Find magnitude
	float forceMagnitude = abs(readings.second.x) + abs(readings.second.y) + abs(readings.second.z);

	// If magnitude is within thresholds, correct
	//if (forceMagnitude > low && forceMagnitude < high)
	//{
	float pitchAcc = atan2(readings.second.y, readings.second.z);
		float pitch = pitch * gyroWeight + pitchAcc * accWeight;
	//}
	readings.first.pitch = pitch;

	return readings;
}

/*
* TODO Write a Kalman filtering system for the acceleration data
*/
Vector3f KalmanFilter(Vector3f acc)
{
	// This just added to make code compile
	return;
}