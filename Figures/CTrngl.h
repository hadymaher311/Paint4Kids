#ifndef __CTrngl_h__
#define __CTrngl_h__

#include "CFigure.h"

class CTrngl : public CFigure {
public:
	CTrngl();
	CTrngl(Point p1, Point p2, Point p3, GfxInfo trngl_gfx_info);

	virtual void Draw(Output* out_p) const;

	virtual void Rotate(int deg);
	virtual void Rotated(bool r);
	virtual bool IsRotate();
	virtual void Save(ofstream& out_file);
	virtual void Load(ifstream& in_file);

	virtual Point CalcCenter();
	virtual void Resize(int resize_factor);

	bool OutOfRange(Point p1, Point p2, Point p3);

	Point p1, p2, p3;
};

#endif /* __CTrngl_h__ */