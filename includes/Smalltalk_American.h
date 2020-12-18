#pragma once
#include <vector>
#include "Smalltalk.h"

class Smalltalk_American :
	public Smalltalk
{
public:
	//this constructor should call the 2 parameter constructor below in it's initializer list
	Smalltalk_American(int iPerson =1);

	//use base class constructor in initializer list to set Nationality and iPerson (See constants for Nationality strings)
	//also prepare the object for use by calling populatePhrases()
	Smalltalk_American(std::string myNationality,int iPerson =1);
	
	~Smalltalk_American(void);
	virtual void populatePhrases();
};

