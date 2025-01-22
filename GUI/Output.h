#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
	void clearToolBar(); //is used only in switching between design & simulation mode
public:
	Output();	

	window* CreateWind(int, int, int , int);
	Input* CreateInput(); //Creates a pointer to the Input object	

	void CreateStatusBar(); //Creates status bar

	//TODO: Complete the following 2 functions
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar(); //Tool bar of the simulation mode

	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearOutputBar(); //Clears the Output bar
	
	void PrintMessage(string msg);	//Prints a message on Status bar
	void DrawString(const int, const int, const string);  //Writes a string in the specified location

	// -- Statements Drawing Functions
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected=false);
	void DrawStart_End(Point p, int width, int height, string type, bool Selected = false);
	void DrawRead_Write(Point p, int width, int height, string type, string Text, bool Selected = false);
	void DrawCondition(Point top, int width, int height, string Text, bool Selected = false);
	void DrawConnector(Point start, Point end, bool Selected = false);
	void DrawExitMsg();
	void DrawCondMsg();
	///Make similar functions for drawing all other statements.

	window* getwindow();
	void DrawImage(image* img, Point p1, Point p2);
	~Output();
};

#endif