/*
	some global constants and definitions to be used in the project.
*/
#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib/CMUgraphics.h" // color

#define SECOND 1000 // second is 1000 milliseconds

enum ActionType //The actions supported (you can add more if needed)
{
    DRAW_FIG_ITM,
    DRAW_LINE, //Draw Line
    DRAW_RECT, //Draw CRectangle
    DRAW_TRI, //Draw Triangle
    DRAW_CIRC, //Draw Circle
    CHNG_DRAW_CLR, //Change the drawing color
    CHNG_FILL_CLR, //Change the filling color
    CHNG_BK_CLR, //Change background color
    DEL, //Delete a figure(s)
    MOVE, //Move a figure(s)
    SELECT,
    CTR, // Figure Actions Control
    RESIZE, //Resize a figure(s)
    ROTATE, //Rotate a figure(s)
    SEND_BACK, //Send a figure to the back of all figures
    BRNG_FRNT, //Bring a figure to the front of all figures
    SAVE, //Save the whole graph to a file
    LOAD, //Load a graph from a file
    ZOOM_IN,
    ZOOM_OUT,
    CUT,
    COPY,
    PASTE,
    HIDE,
    SCRAMBLE,
    UNDO,
    REDO,

	PICK_COLOR,
	PICK_TYPE,
	PICK_AREA,
	PICK_COL_TYP,

    EXIT, //Exit the application

	DRAWING_AREA, //A click on the drawing area
	PLAYING_AREA,
	COLOR_BAR, //A Click On The Color Bar
	STATUS, //A click on the status bar
	EMPTY, //A click on empty place in the toolbar


	TO_DRAW, //Switch interface to Draw mode
	TO_PLAY, //Switch interface to Play mode
	DRAG
};

struct Point // To be used for figures points
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
	Point() : x(0), y(0) {}
	Point operator+(const Point& p)
	{
		return Point(this->x + p.x, this->y + p.y);
	}
	Point operator-(const Point& p)
	{
		return Point(this->x - p.x, this->y - p.y);
	}
	Point operator+(const int& num)
	{
		return Point(this->x + num, this->y + num);
	}
	Point operator-(const int& num)
	{
		return Point(this->x - num, this->y - num);
	}
	bool operator>(const Point& p) const
	{
		return ((this->x > p.x) && (this->y > p.y)) ? true : false;
	}

	bool operator<(const Point& p) const
	{
		return ((this->x > p.x) && (this->y > p.y)) ? false : true;
	}
	bool operator==(const Point& p)
	{
		return (this->x == p.x) && (this->y == p.y);
	}
	bool operator!=(const Point& p)
	{
		return !((this->x == p.x) && (this->y == p.y));
	}
};

#define null_point Point(0, 0)

struct GfxInfo // Graphical info of each figure (you may add more members)
{
	color draw_clr = BLACK; // Draw color of the figure
	color fill_clr = WHITE; // Fill color of the figure
	bool is_filled = false; // CFigure Filled or not
	int border_width = 1; // Width of figure borders
};

#endif