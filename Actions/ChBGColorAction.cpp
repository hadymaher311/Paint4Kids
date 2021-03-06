#include "ChBGColorAction.h"

ChBGColorAction::ChBGColorAction(ApplicationManager* app_p)
    : Action(app_p)
{
}

void ChBGColorAction::ReadActionParameters()
{
    //Get a Pointer to the Input / Output Interfaces
    Output* out_p = manager_p->GetOutput();
    Input* in_p = manager_p->GetInput();
    int x, y;
    out_p->PrintMessage("Choose Your Favourite Color");
    out_p->CreateColorBar();
    in_p->GetClick(x, y);
    lastC = C;
    C = in_p->GetColor(x, y);
    out_p->ClearStatusBar();
	out_p->ClearTempToolbar();
}

void ChBGColorAction::Execute(bool redo)
{
    Output* out_p = manager_p->GetOutput();
    out_p->SetBkGrndColor(C);
    out_p->ClearDrawArea();
}

void ChBGColorAction::Undo()
{
    Output* out_p = manager_p->GetOutput();
    out_p->SetBkGrndColor(lastC);
}