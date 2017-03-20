#ifndef CFIGURE_H
#define CFIGURE_H

#include "../DEFS.h"
#include "../GUI/Output.h"

// Base class for all figures
class Figure
{
public:
    Figure();
    Figure(const Figure& figure_gfx_info);
    
    void SetSelected(bool s); 
    bool IsSelected() const; 

    virtual void Draw(Output* out_p) const = 0; 

    void ChngDrawClr(color draw_clr); // changes the figure's drawing color
    void ChngFillClr(color filling_clr); // changes the figure's filling color

    /// The following functions should be supported by the figure class
    /// It should be overridden by each inherited figure

    /// Decide the parameters that you should pass to each function

    virtual void Rotate() = 0;
    virtual void Resize() = 0;
    virtual void Move() = 0;	

    virtual void Save(ofstream &out_file) = 0;	
    virtual void Load(ifstream &in_file) = 0;	

    virtual void PrintInfo(Output* out_p) = 0;	// on the status bar

    color draw_clr = BLACK; // Draw color of the figure
    color fill_clr = WHITE; // Fill color of the figure
    bool is_filled = false; // Figure Filled or not
    int border_width = 1; // Width of figure borders

    int z_index = std::numeric_limits<int>::max(); // level of object on window, default to max size of int

protected:
    int id; // Each figure has an id
    bool selected = false; // true if the figure is selected.
};

#endif