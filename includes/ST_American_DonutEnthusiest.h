#pragma once
#include "Smalltalk_American.h"
class ST_American_DonutEnthusiest :
	public Smalltalk_American
{
public:
	//use base class constructor in initializer list to set Nationality and iPerson (See constants for Nationality strings)
	//also prepare the object for use by calling populatePhrases()
	ST_American_DonutEnthusiest(int i =1);
	virtual ~ST_American_DonutEnthusiest(void);
	
	//base class populatePhrases() will be called first as part of its construction
	//before this class calls populate phrases as part of its construction
	//the end result is mySmallTalk will contain first the base class phrases and 
	//then ST_American_DonutEnthusiest phrases
	virtual void populatePhrases();
};
