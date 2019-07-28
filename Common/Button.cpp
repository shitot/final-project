#include "Button.h"
#include "Control.h"

Button::Button(Border* Bborder, short Bleft, short Btop, string Bvalue) : Control(Bleft, Btop, Bborder), value(Bvalue), isClicked(FALSE)
{
	width = static_cast<int>(Bvalue.size() + 2);
}

void Button::mousePressed(int x, int y, bool isLeft)
{
	OutputDebugString("press");
	if (y == top && (x > left && x < (left + static_cast<int>(value.size()) - 1)))
	{
		if (!isClicked)
		{
			this->flipBgToWhite();
			isClicked = TRUE;
		}
		else
		{
			this->flipBgToBlack();
			isClicked = FALSE;
		}
	}


	for (int i = 0; i < events.size(); i++) 
	{
		events[i]->buttonEvent();
	}
	
}

int Button::getWidth() 
{
	return width; 
}

void Button::setEvent(Control* control)
{
	events.push_back(control);
}

void Button::draw(Graphics & g, int x, int y, size_t z)
{
	g.setBackground(bgColor);
	g.setForeground(fgColor);
	border->drawBorder(g, x, y,static_cast<int>(value.size()) + 2, 4);
	g.setCursorVisibility(FALSE);
	g.moveTo(x + 1, y + 1);
	g.write(value);
}

Button::~Button() {}
