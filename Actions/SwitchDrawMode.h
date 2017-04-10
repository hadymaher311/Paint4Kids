#ifndef __SwitchDrawMode_H__
#define __SwitchDrawMode_H__

#include "../ApplicationManager.h"
#include "Action.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

//Add CRectangle Action class
class SwitchDrawMode : public Action {
public:
    SwitchDrawMode(ApplicationManager* app_p);

    virtual void ReadActionParameters();
    virtual void Execute();
};

#endif