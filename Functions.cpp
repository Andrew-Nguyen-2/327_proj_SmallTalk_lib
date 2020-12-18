//
/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: andrew
 */
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

//create a vector with appropriate numbers of Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
//objects using unique pointers.  Since we are using c++11 returning this vector by value is fine since the 
//compiler will move the vector on return rather than recreate it (this means there is no copy penalty)
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	
	//create a vector to hold SmallTalk unique pointers
	vector<unique_ptr<Smalltalk>> myVector;

	//add brits to vector
	for (int i = 0; i < numBrit; i++){
		unique_ptr<Smalltalk> brit(new Smalltalk_Brit(i));
		myVector.push_back(move(brit));
	}

	//add americans  to vector
	for (int i = 0; i < numAmerican; i++){
		unique_ptr<Smalltalk> american(new Smalltalk_American(i));
		myVector.push_back(move(american));
	}

	//add american donut enthusiest  to vector
	for (int i = 0; i < numbAmericanDonutEnthusiest; i++){
		unique_ptr<Smalltalk> donut(new ST_American_DonutEnthusiest(i));
		myVector.push_back(move(donut));
	}

	//create some watches (as long as number watches <= numb people)
	//then give the watches away to first NUM_WATCHES people in the vector
	// when you are finished using the vector you return
	//from this function(see Smalltalk header for hints)

	int numPeople = myVector.size();

	if (numWatches > numPeople){
		numWatches = numPeople;
	}

	for (int i = 0; i < numWatches; i++){
		unique_ptr<Watch> pWatch(new Watch());
		myVector[i]->giveWatch(pWatch);
	}

	//return your vector
	return myVector;
}


