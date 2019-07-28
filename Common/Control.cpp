#include "Control.h"


Control* Control::focusCtl = nullptr;
Control::Control()
{
}

Control::Control(short _left, short _top) : left(_left), top(_top) , bgColor(Color::Black) , fgColor(Color::White) , border(NULL)
{
}

Control::Control(short _left, short _top, Border * _border) : left(_left), top(_top), bgColor(Color::Black), fgColor(Color::White), border(_border)
{
}



Control::~Control()
{
}

void Control::flipBgToWhite()
{
	bgColor = Color::White;
	fgColor = Color::Black;
}

void Control::flipBgToBlack()
{
	bgColor = Color::Black;
	fgColor = Color::White;
}
