/*
 * Smalltalk_American.cpp
 *
 *  Created on: Dec 8, 2020
 *      Author: andrew
 */


#include "./includes/Smalltalk_American.h"
#include "./includes/constants.h"

//this constructor should call the 2 parameter constructor below in it's initializer list
Smalltalk_American::Smalltalk_American(int iPerson): Smalltalk(AMERICAN, iPerson){
}

//use base class constructor in initializer list to set Nationality and iPerson (See constants for Nationality strings)
//also prepare the object for use by calling populatePhrases()
Smalltalk_American::Smalltalk_American(std::string myNationality,int iPerson): Smalltalk(myNationality, iPerson){
}

Smalltalk_American::~Smalltalk_American(void){
}
void Smalltalk_American::populatePhrases(){
	mySmallTalk.clear();
	mySmallTalk.push_back(AMERICAN_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_PHRASE_5);
}
