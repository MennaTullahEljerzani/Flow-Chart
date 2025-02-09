#ifndef ADD_CONDITION_H
#define ADD_CONDITION_H

#include "Action.h"
#include "AddCondition.h"
#include "../Statements/Condition.h"

//Add Simple Assignment Statement Action
//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements

class AddCondition : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddCondition(ApplicationManager* pAppManager);

	//Read Condition statements position
	virtual void ReadActionParameters();

	//Create and add an Condition statement to the list of statements
	virtual void Execute();

};

#endif