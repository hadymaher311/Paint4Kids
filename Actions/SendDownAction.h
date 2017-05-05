#ifndef _DOWN_
#define _DOWN_

#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "Action.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

class SendDownAction : public Action 
{
public:
    SendDownAction(ApplicationManager* app_p);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual void Undo();
};

#endif // !_DOWN_