#ifndef __AddTrnglAction_h__
#define __AddTrnglAction_h__

#include "../ApplicationManager.h"
#include "../Figures/CTrngl.h"
#include "Action.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

class AddTrnglAction : public Action {
public:
    AddTrnglAction(ApplicationManager* app_p);

    virtual void ReadActionParameters();
    virtual void Execute(bool redo = false);

    virtual void Undo();

private:
    CTrngl* trngl;

    unsigned int id;
    GfxInfo gfx;
    Point p1, p2, p3;
};

#endif /* __AddTrnglAction_h__ */
