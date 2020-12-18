#pragma once
#include "Smalltalk.h"

class Smalltalk_Brit :
	public Smalltalk
{
public:
	//use base class constructor in initializer list to set Nationality and iPerson (See constants for Nationality strings)
	//also prepare the object for use by calling populatePhrases()
	Smalltalk_Brit(int iPerson=1);
	virtual ~Smalltalk_Brit(void);
	virtual void populatePhrases(); 
};

