/*
 * ST_American_DonutEnthusiest.cpp
 *
 *  Created on: Dec 8, 2020
 *      Author: andrew
 */

#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/constants.h"

//use base class constructor in initializer list to set Nationality and iPerson (See constants for Nationality strings)
//also prepare the object for use by calling populatePhrases()
ST_American_DonutEnthusiest::ST_American_DonutEnthusiest(int i): Smalltalk_American(AMERICAN_DE, i){
}
ST_American_DonutEnthusiest::~ST_American_DonutEnthusiest(void){
}

//base class populatePhrases() will be called first as part of its construction
//before this class calls populate phrases as part of its construction
//the end result is mySmallTalk will contain first the base class phrases and
//then ST_American_DonutEnthusiest phrases
void ST_American_DonutEnthusiest::populatePhrases(){
	mySmallTalk.clear();
	Smalltalk_American::populatePhrases();
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_5);
}
