#include "EventInterfacing.h"
#include "RVC.h"

class EventInterfacing : EventInterface
{
public:
	float walkAcc;
	float walkDecc;
	Rift rift;

	EventInterfacing::EventInterfacing(Rift connection, float accThreshold, float deccThreshold)
	{
		this->rift = connection;
		this->walkAcc = accThreshold;
		this->walkDecc = deccThreshold;
	}

	EventInterfacing::~EventInterfacing()
	{
		this->rift.clear();
	}

	/*
	* Sets threshold values for acceleration and decceleration.
	*
	* @updates walkAcc, walkDecc
	*	Updates walkAcc and walkDecc to the values passed in.
	*		walkAcc = acc && walkDecc = decc
	*/
	void setThreshold(float acc, float decc)
	{
		walkAcc = acc;
		walkDecc = decc;
	}

	/*
	* Finds and returns threshold values for acceleration to walking.
	*
	* @requires 
	*	Acceleration data is valid
	*		accData.length > 0 && accData != NULL
	*
	* @return 
	*	A threshold value that signifies that a person has begun walking
	*/
	float findAccelerationThreshold(std::vector<float> & accData)
	{
		// TODO write algorithm to quickly find a threshold for beginning walking from a vector.
	};

	/*
	* Finds and returns threshold values for decceleration to stop.
	*
	* @return
	*	A threshold value that signifies that a person has begun to stop walking
	*/
	float findDeccelerationThreshold(std::vector<float> accData)
	{
		// TODO write algorithm to quickly find threshold for decceleration.
	};

	/*
	* Simple implementation of movement in OpenSim. If threshold values are broken, we
	* move the avatar in virtual world by "pressing" a key.
	*
	*/
	void move()
	{
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0;
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;

		float zAccel = rift.CorrectedAcceleration().z;
		// If we detect acceleration, assume walking until we detect deceleration
		if (zAccel < this->walkAcc)
		{
			// Once we detected decceleration, stop walking.
			while (zAccel < this->walkDecc)
			{
				ip.ki.wVk = 0x57;
				ip.ki.dwFlags = 0;
				SendInput(1, &ip, sizeof(INPUT));
				zAccel = rift.CorrectedAcceleration().z;
			}
		}

		//Release key
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));
	};
	
};