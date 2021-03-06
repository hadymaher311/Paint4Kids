#ifndef _PICK_TYPE_
#define _PICK_TYPE_

#include "../ApplicationManager.h"
#include "Action.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

class PickByType : public Action {

public:
	PickByType(ApplicationManager *app_p);
	~PickByType();

	virtual void ReadActionParameters();
	virtual void Execute(bool redo = false);
	virtual void Undo();

private:
	deque<CFigure *> figures;

	int GetNumFigsSameType(CFigure *figure);

	void DeleteCorrect(int id);
};


#endif // !_PICK_TYPE_