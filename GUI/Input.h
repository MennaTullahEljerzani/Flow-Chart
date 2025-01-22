#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h"
#include "..\HelperFn.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   //Class forward declaration
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(Point &P) const;//Gets coordinate where user clicks
	
	//TODO: Complete the implementation of the following function
	double GetValue(Output* pO, double s) const;	// Reads a double value from the user 

	string GetString(Output* pO, string s) const ; //Returns a string entered by the user

	string GetVariable(Output* pO) const;

	char GetArithOperator(Output* pO) const; //Returns an arith operator entered by the user

	//Returns a comparison operator (==, !=, <, <=, > or >=).entered by the user
	string GetCompOperator(Output* pO) const; 

	//TODO: Complete the implementation of the following function
	ActionType GetUserAction(Point& P) const; //Reads the user click and maps it to an action
	image StoreImage(image img, Point p1, Point p2) const;
	~Input();
};

#endif