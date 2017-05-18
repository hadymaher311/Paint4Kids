#include "CopyAction.h"

CopyAction::CopyAction(ApplicationManager* app_p)
    : Action(app_p, false)
{
}

void CopyAction::ReadActionParameters()
{
}

void CopyAction::Execute(bool redo)
{
    manager_p->FillClipboardWithSelected();
}

void CopyAction::Undo()
{
}