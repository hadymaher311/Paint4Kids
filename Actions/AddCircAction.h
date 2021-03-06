#ifndef __AddCircAction_h__
#define __AddCircAction_h__

#include "../ApplicationManager.h"
#include "../Figures/CCircle.h"
#include "Action.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

class AddCircAction : public Action {
public:
    AddCircAction(ApplicationManager* app_p);

    virtual void ReadActionParameters();
    virtual void Execute(bool redo = false);

    virtual void Undo();

private:
    CCircle* circ;

    // properities
    unsigned int id;
    GfxInfo gfx;
    Point p1, p2;
    int radius;
};

#endif /* __AddCircAction_h__ */