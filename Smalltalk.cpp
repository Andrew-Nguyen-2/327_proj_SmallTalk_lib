/*
 * Smalltalk.cpp
 *
 *  Created on: Dec 8, 2020
 *      Author: andrew
 */


#include "./includes/Smalltalk.h"
#include "./includes/constants.h"

//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish between objects of the same type
Smalltalk::Smalltalk(std::string myNationality,int iPerson): nationality(myNationality), iPerson(iPerson), current_phrase(0){
}

Smalltalk::~Smalltalk(void){
}

//cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending
//with the last and then it starts over
//takes the form Nationality iPerson: phrase
//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2
//AMERICAN 10:Why yes, I would like to supersize that
std::string Smalltalk::saySomething(){
	this->populatePhrases();

	const int NUM_AMERICAN_PHRASES = 5;
	const int NUM_AMERICAN_DE_PHRASES = 10;
	const int NUM_BRIT_PHRASES = 7;
	const std::string NO_NATIONALITY = "Nationality is not American, British, or American Donut Enthusiast";

	if (this->nationality == AMERICAN){
		int i = this->current_phrase % NUM_AMERICAN_PHRASES;
		this->current_phrase++;
		return this->mySmallTalk[i];
	}
	if (this->nationality == AMERICAN_DE){
		int i = this->current_phrase % NUM_AMERICAN_DE_PHRASES;
		this->current_phrase++;
		return this->mySmallTalk[i];
	}
	if (this->nationality == BRIT){
		int i = this->current_phrase % NUM_BRIT_PHRASES;
		this->current_phrase++;
		return this->mySmallTalk[i];
	}

	return NO_NATIONALITY;
}

//returns the time (if pWatch contains a watch ) in the form of THE_CURRENT_TIME_IS: (from the actual watch object itself) and then the time
//or I_DO_NOT_HAVE_A_WATCH string (if pWatch does not contain a watch)
std::string Smalltalk::getTime(){
	if (pWatch){
		return pWatch->getTime();
	}
	return I_DO_NOT_HAVE_A_WATCH;
}

//if this object has a watch it is taken away, otherwise an empty unique_ptr is returned
// This transaction simulates giving away a watch
std::unique_ptr<Watch> Smalltalk::takeWatch(){
	std::unique_ptr<Watch> watch;
	if (!this->pWatch){
		return watch;
	}
	watch = std::move(this->pWatch);
	return watch;
}

//if pWatch is NULL return false
//if already have a watch then return false and dont change pWatch pointer
//otherwise accept watch and use std::move to move watch
//from pWatch to this->pWatch and return true
bool Smalltalk::giveWatch(std::unique_ptr<Watch> &pWatch){
	if (pWatch == NULL){
		return false;
	}
	if (this->pWatch){
		return false;
	}
	this->pWatch = std::move(pWatch);
	return true;
}

void Smalltalk::populatePhrases(){
}
