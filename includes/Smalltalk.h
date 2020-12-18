#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Watch.h"

class Smalltalk
{
public:
	//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish between objects of the same type
	Smalltalk(std::string myNationality,int iPerson=1);
	
	virtual ~Smalltalk(void);
	
	//cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending 
	//with the last and then it starts over
	//takes the form Nationality iPerson: phrase
	//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2 
	//AMERICAN 10:Why yes, I would like to supersize that
	std::string saySomething();

	//returns the time (if pWatch contains a watch ) in the form of THE_CURRENT_TIME_IS: (from the actual watch object itself) and then the time
	//or I_DO_NOT_HAVE_A_WATCH string (if pWatch does not contain a watch)
	std::string getTime();

	//if this object has a watch it is taken away, otherwise an empty unique_ptr is returned
	// This transaction simulates giving away a watch
	std::unique_ptr<Watch>  takeWatch();

	//if pWatch is NULL return false
	//if already have a watch then return false and dont change pWatch pointer
	//otherwise accept watch and use std::move to move watch
	//from pWatch to this->pWatch and return true
	bool giveWatch(std::unique_ptr<Watch> &pWatch);

	//Abstract Base Class (ABC), implement in derived classes
	virtual void populatePhrases()=0;
	
protected:
	const std::string			nationality;	//populated by derived classes using initilizer list from constants.h
	std::vector<std::string>	mySmallTalk;	//populated by populatePhrases in derived classes
	int							iPerson;		//what number this person is (just a way to track objects)
	int 						current_phrase;	//which phrase was last returned (use % operator to cycle through phrases)
	std::unique_ptr<Watch> pWatch;		//if 0 don't have a watch, otherwise does have a watch
};

