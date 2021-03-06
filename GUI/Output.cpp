#include "Output.h"

Output::Output()
{
	// Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1350;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;

	// ToolBar Parameters
	UI.ToolBarHeight = 50;
	UI.ToolBarWidth = UI.width;
	UI.ToolBarX = 0;
	UI.ToolBarY = 0;

	// Temp ToolBar Parameters
	UI.TToolBarWidth = UI.width;
	UI.TToolBarHeight = 50;
	UI.TToolBarX = 0;
	UI.TToolBarY = UI.ToolBarHeight;

	// Status Bar Parameters
	UI.StatusBarWidth = UI.width;
	UI.StatusBarHeight = 60;
	UI.StatusBarX = 0;
	UI.StatusBarY = UI.height - UI.StatusBarHeight;

	// Items Parameters
	UI.MenuItemWidth = 50;
	UI.MenuItemHeight = 50;

	// Draw Area Parameters
	UI.DrawAreaWidth = UI.width;
	UI.DrawAreaHeight = UI.height - (UI.StatusBarHeight + UI.ToolBarHeight);
	UI.DrawAreaX = 0;
	UI.DrawAreaY = UI.ToolBarHeight; /*+ UI.TToolBarHeight*/

									 // Play Area Parameters
	UI.playAreaWidthone = UI.width / 2;
	UI.playAreaWidthtwo = UI.playAreaWidthone;
	UI.playAreaHeight = UI.height - UI.StatusBarHeight - UI.ToolBarHeight;

	UI.DrawColor = BLACK; // Drawing color
	UI.LastDrawColor = UI.DrawColor;

	UI.FillColor = GREEN; // Filling color
	UI.LastFillColor = UI.FillColor;
	UI.MsgColor = WHITE; // Messages color
	UI.BkGrndColor = WHITE; // Background color					/// I
							// Changed This [Back To Here To Customize The Tool Bar Background
							// Color]
	UI.HighlightColor = MAGENTA; // This color should NOT be used to draw figures.
								 // use if for highlight only
	UI.StatusBarColor = ABLUE;
	UI.PenWidth = 3; // width of the figures frames	
	UI.LastPenWidth = UI.PenWidth;

					 // Create the output window
	wind_p = CreateWind(UI.width, UI.height, UI.wx, UI.wy);

	wind_p->ChangeTitle("Paint for Kids - Programming Techniques Project");
	wind_p->SetWaitClose(false);

	CreateDrawToolBar();
	ClearStatusBar();
}

Input* Output::CreateInput() const
{
	Input* in_p = new Input(wind_p);
	return in_p;
}

//======================================================================================//
//								Interface Functions
////
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(UI.DrawAreaX, UI.DrawAreaY, UI.DrawAreaX + UI.DrawAreaWidth, UI.DrawAreaY + UI.DrawAreaHeight);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	wind_p->SetPen(UI.StatusBarColor, 1);
	wind_p->SetBrush(UI.StatusBarColor);
	wind_p->DrawRectangle(UI.StatusBarX, UI.StatusBarY, UI.StatusBarX + UI.StatusBarWidth, UI.StatusBarY + UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar(bool clear_msg)
{
	// Clear Status bar by drawing a filled white rectangle
	wind_p->SetPen(UI.StatusBarColor, 1);
	wind_p->SetBrush(UI.StatusBarColor);
	wind_p->DrawRectangle(UI.StatusBarX, UI.StatusBarY, UI.StatusBarX + UI.StatusBarWidth, UI.StatusBarY + UI.StatusBarHeight);
	if (UI.IsFilled == true && UI.InterfaceMode == MODE_DRAW) {
		Point p1;
		p1.y = UI.StatusBarY + (UI.StatusBarHeight / 2) - 10;
		p1.x = UI.width - 35;
		int raduis = 15;
		GfxInfo info;
		info.is_filled = true;
		info.border_width = 1;
		info.draw_clr = UI.DrawColor;
		info.fill_clr = UI.FillColor;
		DrawCircle(p1, raduis, info, false);
	}

	if (!clear_msg)
		PrintMessage(last_printed_msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	ClearToolbar();

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First prepare List of images for each menu item
	// To control the order of these images in the menu,
	// reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_FIG] = "images\\MenuItems\\borderPen.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_CHDC] = "images\\MenuItems\\border.jpg";
	MenuItemImages[ITM_CHFC] = "images\\MenuItems\\color_picker.jpg";
	MenuItemImages[ITM_CHBGC] = "images\\MenuItems\\paint_bucket.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\open.jpg";
	MenuItemImages[ITM_CTR] = "images\\MenuItems\\control.jpg";
	MenuItemImages[ITM_ZOOM_IN] = "images\\MenuItems\\Zin.jpg";
	MenuItemImages[ITM_ZOOM_OUT] = "images\\MenuItems\\Zout.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";

	// Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		wind_p->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, UI.ToolBarY, UI.MenuItemWidth, UI.ToolBarHeight);
}

void Output::CreateFigItems() const
{
	UI.TToolBarWidth = 200;
	ClearTempToolbar();
	wind_p->isfigitems = true;

	string MenuItemImages[FIG_ITM_COUNT];
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\tringle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";

	for (int i = 0; i < FIG_ITM_COUNT; i++)
		wind_p->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, UI.TToolBarY, UI.MenuItemWidth, UI.TToolBarHeight);
}
void Output::CreateFigActions() const
{
	UI.TToolBarWidth = 450;
	ClearTempToolbar();
	wind_p->isfigactions = true;

	string MenuItemImages[FIG_ACT_COUNT];
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\rotate.jpg";
	MenuItemImages[ITM_SEND_BACK] = "images\\MenuItems\\down.jpg";
	MenuItemImages[ITM_BRING_FRONT] = "images\\MenuItems\\up.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";

	for (int i = 0; i < FIG_ACT_COUNT; i++)
		wind_p->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, UI.TToolBarY, UI.MenuItemWidth, UI.TToolBarHeight);
}
void Output::CreateBorderToolbar() const
{
	UI.TToolBarWidth = 200;
	ClearTempToolbar();
	wind_p->isborderwidth = true;

	string MenuItemImages[4];
	MenuItemImages[0] = "images\\MenuItems\\very_small.jpg";
	MenuItemImages[1] = "images\\MenuItems\\small.jpg";
	MenuItemImages[2] = "images\\MenuItems\\mid.jpg";
	MenuItemImages[3] = "images\\MenuItems\\big.jpg";

	for (int i = 0; i < 4; i++)
		wind_p->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, UI.TToolBarY, UI.MenuItemWidth, UI.TToolBarHeight);
}

void Output::CreateResize() const
{
	ClearTempToolbar();
	UI.TToolBarWidth = 200;
	wind_p->isborderwidth = true;

	string MenuItemImages[4];
	MenuItemImages[0] = "images\\MenuItems\\resize_0.25.jpg";
	MenuItemImages[1] = "images\\MenuItems\\resize_0.5.jpg";
	MenuItemImages[2] = "images\\MenuItems\\resize_2.jpg";
	MenuItemImages[3] = "images\\MenuItems\\resize_4.jpg";

	for (int i = 0; i < 4; i++)
		wind_p->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, UI.TToolBarY, UI.MenuItemWidth, UI.TToolBarHeight);
}

void Output::CreatePickBar() const
{
	UI.TToolBarWidth = 200;
	ClearTempToolbar();
	wind_p->ispickbar = true;

	string MenuItemImages[PICK_ITM_COUNT];
	MenuItemImages[ITM_PICK_COLOR] = "images\\MenuItems\\ByColor.jpg";
	MenuItemImages[ITM_PICK_TYPE] = "images\\MenuItems\\Type2.jpg";
	MenuItemImages[ITM_PICK_AREA] = "images\\MenuItems\\Area.jpg";
	MenuItemImages[ITM_PICK_COL_TYP] = "images\\MenuItems\\Type&Color.jpg";

	for (int i = 0; i < PICK_ITM_COUNT; i++)
		wind_p->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, UI.TToolBarY, UI.MenuItemWidth, UI.TToolBarHeight);
}

void Output::CreateRestartGame() const
{
	ClearToolbar();
	string MenuItemImages[2];
	MenuItemImages[0] = "images\\MenuItems\\restart.jpg";
	MenuItemImages[1] = "images\\MenuItems\\exit.jpg";

	for (int i = 0; i < 2; i++)
		wind_p->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, UI.ToolBarY, UI.MenuItemWidth, UI.ToolBarHeight);
}

void Output::CreateColorBar() const
{
	UI.TToolBarWidth = UI.width;
	wind_p->iscolorbar = true;
	wind_p->DrawImage("images\\MenuItems\\coloring2.jpg", UI.TToolBarX, UI.TToolBarY, UI.TToolBarWidth, UI.TToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolbar();

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICK_HIDE] = "images\\MenuItems\\find.jpg";
	MenuItemImages[ITM_SCR_FIND] = "images\\MenuItems\\scramble.jpg";
	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\to_draw.jpg";
	MenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\exit.jpg";

	// Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		wind_p->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0,
			UI.MenuItemWidth, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	wind_p->SetPen(UI.BkGrndColor, UI.PenWidth);
	wind_p->SetBrush(UI.BkGrndColor);
	wind_p->DrawRectangle(UI.DrawAreaX, UI.DrawAreaY, UI.DrawAreaX + UI.DrawAreaWidth, UI.DrawAreaY + UI.DrawAreaHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolbar() const
{
	wind_p->SetBrush(AGRAY);
	wind_p->SetPen(AGRAY);
	wind_p->DrawRectangle(UI.ToolBarX, UI.ToolBarY, UI.ToolBarX + UI.ToolBarWidth, UI.ToolBarY + UI.ToolBarHeight);
}

void Output::ClearTempToolbar() const
{
	wind_p->isfigactions = false;
	wind_p->isfigitems = false;
	wind_p->iscolorbar = false;
	wind_p->SetBrush(UI.BkGrndColor);
	wind_p->SetPen(UI.BkGrndColor);
	wind_p->DrawRectangle(UI.TToolBarX, UI.TToolBarY, UI.TToolBarX + UI.TToolBarWidth, UI.TToolBarY + UI.TToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg, color msgc, bool save_msg) // Prints a message on status bar
{
	ClearStatusBar(); // First clear the status bar

	wind_p->SetPen(msgc, 50);
	wind_p->SetFont(20, PLAIN, BY_NAME, "Arial");
	wind_p->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.25), msg);

	last_printed_msg = (save_msg) ? msg : "";
}
//======================================================================================//
//								Figures Drawing Functions
////
//======================================================================================//

void Output::DrawRect(Point p1, Point p2, GfxInfo rect_gfx_info, bool selected) const
{
	Point pf1 = TranslatePoint(p1);
	Point pf2 = TranslatePoint(p2);

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; // CFigure should be drawn highlighted
	else
		DrawingClr = rect_gfx_info.draw_clr;

	int bord_size = rect_gfx_info.border_width;

	bord_size = AdjustBorder(bord_size); //Adjusting border size for zooming if zoom_in increase border size. If zoom_out reduce border size

	wind_p->SetPen(DrawingClr, bord_size); // Set Drawing color & Width

	drawstyle style;
	if (rect_gfx_info.is_filled) {
		style = FILLED;
		wind_p->SetBrush(rect_gfx_info.fill_clr);
	}
	else
		style = FRAME;

	wind_p->DrawRectangle(pf1.x, pf1.y, pf2.x, pf2.y, style);
}

void Output::DrawCircle(Point p1, int radius, GfxInfo circ_gfx_info, bool selected) const
{
	Point pf1 = TranslatePoint(p1);

	radius *= (int)pow(2, zoom_scale);

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; // CFigure should be drawn highlighted
	else
		DrawingClr = circ_gfx_info.draw_clr;

	int bord_size = circ_gfx_info.border_width;

	bord_size = AdjustBorder(bord_size); //Adjusting border size for zooming if zoom_in increase border size. If zoom_out reduce border size

	wind_p->SetPen(DrawingClr, bord_size); // Set Drawing color & Width

	drawstyle style;
	if (circ_gfx_info.is_filled) {
		style = FILLED;
		wind_p->SetBrush(circ_gfx_info.fill_clr);
	}
	else
		style = FRAME;

	wind_p->DrawCircle(pf1.x, pf1.y, radius, style);
}

void Output::DrawLine(Point p1, Point p2, GfxInfo line_gfx_info, bool selected) const
{
	Point pf1 = TranslatePoint(p1);
	Point pf2 = TranslatePoint(p2);

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; // CFigure should be drawn highlighted
	else
		DrawingClr = line_gfx_info.draw_clr;

	int bord_size = line_gfx_info.border_width;

	bord_size = AdjustBorder(bord_size); //Adjusting border size for zooming if zoom_in increase border size. If zoom_out reduce border size

	wind_p->SetPen(DrawingClr, bord_size); // Set Drawing color & Width

	drawstyle style = FRAME;

	wind_p->DrawLine(pf1.x, pf1.y, pf2.x, pf2.y, style);
}

void Output::DrawTriangle(Point p1, Point p2, Point p3, GfxInfo trngl_gfx_info, bool selected) const
{
	Point pf1 = TranslatePoint(p1);
	Point pf2 = TranslatePoint(p2);
	Point pf3 = TranslatePoint(p3);

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; // CFigure should be drawn highlighted
	else
		DrawingClr = trngl_gfx_info.draw_clr;

	int bord_size = trngl_gfx_info.border_width;

	bord_size = AdjustBorder(bord_size); //Adjusting border size for zooming if zoom_in increase border size. If zoom_out reduce border size

	wind_p->SetPen(DrawingClr, bord_size); // Set Drawing color & Width

	drawstyle style;
	if (trngl_gfx_info.is_filled) {
		style = FILLED;
		wind_p->SetBrush(trngl_gfx_info.fill_clr);
	}
	else
		style = FRAME;

	wind_p->DrawTriangle(pf1.x, pf1.y, pf2.x, pf2.y, pf3.x, pf3.y, style);
}

void Output::CreateDrawArea() const
{
	wind_p->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::GetDrawColor() const // get current drwawing color
{
	return UI.DrawColor;
}

color Output::GetFillColor() const // get current filling color
{
	return UI.FillColor;
}

int Output::GetPenWidth() const // get current pen width
{
	return UI.PenWidth;
}

int Output::GetZoomScale() const
{
	return zoom_scale;
}

Point Output::GetZoomPoint() const
{
	return zoom_point;
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::SetZoomScale(int z)
{
	zoom_scale = z;
}

void Output::SetZoomPoint(Point z_point)
{
	zoom_point = z_point;
}

void Output::SetDrawColor(color given_clr)
{
	UI.DrawColor = given_clr;
}

void Output::SetFillColor(color given_clr)
{
	UI.FillColor = given_clr;
}

void Output::SetPenWidth(int new_width)
{
	if (new_width < 0)
	{
		cerr << "cant set pen width to negative number, current penwidth is " << UI.PenWidth
			<< " and given new_width is " << new_width << endl;

		return;
	}
	UI.PenWidth = new_width;
}

void Output::SetBkGrndColor(color given_clr)
{
	UI.BkGrndColor = given_clr;
}
//////////////////////////////////////////////////////////////////////////////////////////
Point Output::TranslatePoint(const Point& g_point) const
{
	/*this equation holds for any point in the drawing area it's based on
	Analytic Geometry where we translate axes to the clicked point multiply
	by the zooming factor and then translate back to the main axes to get
	the new point after zooming the following piece of code check the pointer
	to know which figure to draw calcuate the new points of the shape then
	draw it*/
	return {
		static_cast<int>(pow(2, zoom_scale) * (g_point.x - zoom_point.x)) + zoom_point.x,
		static_cast<int>(pow(2, zoom_scale) * (g_point.y - zoom_point.y)) + zoom_point.y
	};
}

int Output::AdjustBorder(const int& border) const
{
	switch (border)
	{
	case 1:
		return AdjustBorder1(border);
	case 3:
		return AdjustBorder3(border);
	case 10:
		return AdjustBorder10(border);
	case 15:
		return AdjustBorder15(border);
	default:
		return border;
	}
}

int Output::AdjustBorder15(const int& border) const
{
	if (zoom_scale < 0)
		switch (zoom_scale)
		{
		case -1:
			return 12;
		case -2:
			return 10;
		case -3:
			return 6;
		case -4:
			return 3;
		case -5:
			return 1;
		}
	else if (zoom_scale > 0)
		return 15;

	return border;
}

int Output::AdjustBorder10(const int& border) const
{
	if (zoom_scale <= 4 && zoom_scale >= -3)
		switch (zoom_scale)
		{
		case 0:
			return 10;
		case 1:
			return 10;
		case 2:
			return 12;
		case 3:
			return 12;
		case 4:
			return 15;
		case -1:
			return 6;
		case -2:
			return 3;
		case -3:
			return 1;
		}
	else if (zoom_scale > 4)
		return 15;
	else if (zoom_scale < -3)
		return 1;

	return border;
}

int Output::AdjustBorder3(const int& border) const
{
	if (zoom_scale <= 6 && zoom_scale >= -2)
		switch (zoom_scale)
		{
		case 0:
			return border;
		case 1:
			return border;
		case 2:
			return 6;
		case 3:
			return 6;
		case 4:
			return 10;
		case 5:
			return 10;
		case 6:
			return 15;
		case -1:
			return 2;
		case -2:
			return 1;
		}
	else if (zoom_scale > 6)
		return 15;
	else if (zoom_scale < -2)
		return 1;

	return border;
}

int Output::AdjustBorder1(const int& border) const
{
	if (zoom_scale <= 8 && zoom_scale >= 2)
		switch (zoom_scale)
		{
		case 2:
			return 3;
		case 3:
			return 3;
		case 4:
			return 6;
		case 5:
			return 6;
		case 6:
			return 10;
		case 7:
			return 10;
		case 8:
			return 15;
		}
	else if (zoom_scale > 8)
		return 15;
	else if (zoom_scale < 0)
		return 1;

	return border;
}
//////////////////////////////////////////////////////////////////////////////////////////
buttonstate Output::ButtonState(button btn, Point& draging_point)
{
	return wind_p->GetButtonState(btn, draging_point.x, draging_point.y);
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output() { delete wind_p; }