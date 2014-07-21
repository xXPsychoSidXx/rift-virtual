#ifndef DATE_H
#define DATE_H
#include "OVR.h"
#include "EulerAngles.h"
#include <string>
#include <utility>
using namespace OVR;

/*
* Handles Oculus Rift events. Contains all the necessary
* variables for connecting to the Oculus Rift and all the functions 
* required to get information from the Oculus Rift and interface it
* to the virtual world.
*
* For future interns: The convention we hold is to have all things
* related to pure connections with the Oculus Rift and events responding to
* the Oculus Rift here. The data from the Oculus Rift is NOT filtered
* DIRECTLY within this class but this class calls upon functions to do so.
* Use this class for all things Oculus related, keep functions that are not
* directly related to the Oculus (ie filters, events, opensim interfaces)
* outside of this file--even if you use them in implementations of functions
* within this class. This organization is done intentionally to maintain differences
* between other technologies that may be integrated (if you are going to integrate 
* something like a kinect write another class).
*/
class Rift
{
public:
	Ptr<DeviceManager>	pManager;
	Ptr<HMDDevice>		pHMD;
	Ptr<SensorDevice>	pSensor;
	SensorFusion*		pFusionResult;
	HMDInfo			Info;
	bool			InfoLoaded;

	// Kernel Methods

	/*
	* Initializes the Oculus Rift connection.
	*
	*/
	virtual void init();

	/*
	* Clears the Oculus Rift connection.
	*/
	virtual void clear();
	
	//End kernel methods

	/*
	* Return raw acceleration data from the Oculus Rift
	*
	* @requires
	*	The Rift connection must be connected properly.
	*		pSensor == true
	*
	* @return 
	*	The raw acceleration data.
	*		< x, y, z> == accelerations in 3D
	*/
	virtual Vector3f RawAcceleration();

	/*
	* Return raw Euler angles from the Oculus Rift
	*
	* @requires
	*	The Rift is connected properly
	*		pSensor
	*
	* @return
	*	instance of class EulerAngles such that EulerAngles.yaw = yaw *
	*											EulerAngles.pitch = pitch *
	*											EulerAngles.roll = roll *
	*	* = of Oculus Rift at the time of the call.
	*/
	virtual EulerAngles RawEulerAngles();

	/*
	* Return the raw orientation of the Oculus Rift in the form of a quaternion
	*
	* @requires
	*	The Rift is connected properly
	*		pSensor
	*
	* @return
	*	A quaternion representing the orientation of the Oculus Rift at the time of
	*	the call
	*/
	virtual Quatf RawOrientation();

	/*
	* Return gravity corrected acceleration of the Oculus Rift.
	*
	* @requires
	*	The rift is connected properly && the standard gravity of the environment
	*	is near to 9.81.
	*		pSensor && STD_GRAV == tolerance(9.81);
	*
	* @return
	*	The acceleration of the Oculus Rift corrected for gravity
	*		<x, y, z> == acceleration in 3D - given that the z acceleration = z acceleration - ((9.81 m/s/s)sin(pitch)) 
	*/
	virtual Vector3f CorrectedAcceleration();

	/*
	* Virtual destructor
	*/
	virtual ~Rift() {};
};

#endif