#pragma once
#include "Action.h"
#include "../Statements/Statement.h"

class Statement;


class Cut :public Action
{
private:
	//static type=2;
	Point Position;
	Statement* Stat;
public:
	Cut(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};

