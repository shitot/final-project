#include "Panel.h"



Panel::Panel(Border * _border, short _left, short _top) :Control(_left, _top, _border) 
{
	
}



void Panel::draw(Graphics & g, int x, int y, size_t z)
{
	g.setBackground(bgColor);
	g.setForeground(fgColor);
	border->drawBorder(g, x, y, width , height);
	for (auto c : controls) {
		c->draw(g,  c->getLeft(), c->getTop(), z);
	}
}

void Panel::mousePressed(int x, int y, bool isLeft)
{
	for (auto c : controls)
	{
		int topY    = c->getTop();
		int leftX   = c->getLeft();
		int widthC  = c->getWidth();
		bool getFocus = c->canGetFocus();
		if (getFocus)
		{
			if ((y > topY && y<topY+height) && (x > leftX && x < (leftX + widthC - 1)))
			{
				Control::setFocus(*c);
				c->mousePressed(x, y, isLeft);
				break;
			}
		}
		else
		{
			if ( (y > topY && y<topY+height) && (x > left && x < (leftX + widthC - 1)))
			{
				c->mousePressed(x, y, isLeft);
				break;
			}
		}
	}
}

void Panel::addControlsToVector(Control * _control)
{
	controls.push_back(_control);
}

Control * Panel::getFirstControl()
	{
	if (controls.size() > 0) {
		if (controls[0]->canGetFocus()) {
			return &(*controls[0]);
		}
	}
	return NULL;
}



void Panel::getAllControls(vector<Control*>* controls)
{
	 *controls = this->controls; 
}


void Panel::setWidth(short _width)
{
	width = _width;
}

void Panel::setHeight(short _height)
{
	height = _height;
}

Panel::~Panel()
{
}
