#include "AddVarAssign.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

#include "AddVarAssign.h" // badal AddRectAction

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddVarAssign::AddVarAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddVarAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pManager->UnSelect();

	while (1)
	{
		pOut->PrintMessage("Variable Assignment Statement: Click to add the statement");
		pIn->GetPointClicked(Position);

		Point P[4];
		P[0].x = Position.x - UI.ASSGN_WDTH / 2;            P[1].x = Position.x - UI.ASSGN_WDTH / 2;             P[2].x = Position.x + UI.ASSGN_WDTH / 2;               P[3].x = Position.x + UI.ASSGN_WDTH / 2;
		P[0].y = Position.y;     P[1].y = Position.y + UI.ASSGN_HI;                                       P[2].y = P[1].y;        P[3].y = P[0].y;
		if (P[0].x > UI.MnItWdth && P[0].y > UI.TlBrWdth && P[1].y < UI.height - UI.StBrWdth)
			if (!pManager->onObject(P[0]) && !pManager->onObject(P[1]) && !pManager->onObject(P[2]) && !pManager->onObject(P[3]))
				break;
		if (pManager->onBars(Position) || pManager->onObject(Position))
		{
			pOut->ClearStatusBar();	return;
		}


	}
	pOut->ClearStatusBar();

}

void AddVarAssign::Execute()
{
	ReadActionParameters();
	if (pManager->onBars(Position) || pManager->onObject(Position))
		return;


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	VarAssign* pAssign = new VarAssign(Corner);

	pManager->AddStatement(pAssign);
	pManager->setEditedDesign(true);
	pManager->UndoRedo();
}
