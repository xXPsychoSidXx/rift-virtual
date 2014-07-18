#ifndef EULERANGLES_H
#define EULERANGLES_H

/*
* Simple plain old data structure to hold Euler angle values. Feel free to add functionality to this,
* but the program does not use this for anything but storing test data in a easily accessible manner with
* a clear naming convention. This should not be used over vector or array, or even just declaring three floats
* unless readibility is necessary as using this will increase run time.
*/
struct EulerAngles
{
	float yaw, pitch, roll;
};

#endif