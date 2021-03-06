#ifndef _PASTEAction_
#define _PASTEAction_

#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "Action.h"
#include "MoveAction.h"

class PasteAction : public Action {
	bool pasted;
public:
    PasteAction(ApplicationManager* app_p);
    ~PasteAction();

    virtual void ReadActionParameters();
    virtual void Execute(bool redo = false);
    virtual void Undo();
private:
    deque<CFigure*> clipboard;
    Point p;
};
#endif