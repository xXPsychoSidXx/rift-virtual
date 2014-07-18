#ifndef FILTER_H
#define FILTER_H
#include "RVC.h"

/*
* A complementary filter for the readings from the accelerometer and gyroscope.
* 
* @param fusion
*	Fusion objected attached to sensor devices
* @return filteredValue
*	
*/
pair<Vector3f, float> ComFilter(pair<EulerAngles, Vector3f> readings);

/*
* A Kalman filter for the corrected accelerometer readings
*/
Vector3f KalmanFilter(Vector3f acc);

#endif