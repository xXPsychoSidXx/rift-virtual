#include "EventInterfacing.h"

class EventInterfacing1 : EventInterface
{
public:
	Rift rift;

	/*
	* Pedometer using accelerometer in the Oculus Rift. 
	*
	* @return
	*	Returns true if the person is walking and returns false if the person is not
	*		if (walking) return true
	*		else return false
	* 
	* @param rift
	*	An instance of the Rift interfacing class
	*/
	virtual bool pedometer(Rift rift)
	{
		// TODO write pedometer algorithm.
		/*
			This passes in the Rift object so maybe filtering will be easier to show here?
			Chances are this will be deprecated once filering is handling within the Rift class.
		*/
	};

		/*
	* Pedometer using accelerometer in the Oculus Rift. 
	*
	* @return
	*	Returns true if the person is walking and returns false if the person is not
	*		if (walking) return true
	*		else return false
	*/
	virtual bool pedometer()
	{
		// TODO write pedometer algorithm. Implementation where rift connection is a member of this class--filtering to
		// be handled on the rift side of things.
	};
};