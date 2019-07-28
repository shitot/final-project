#include "MassageBox.h"

MassageBox::MassageBox(short _left, short _top, string message) :
	Control(_left, _top), label(left, _top, message), panel(new LineBorder(), _left, _top), focus(FALSE)
{
	panel.setFocus(panel);
}

void MassageBox::onFocus(bool flag)
{
	focus = flag;
}

MassageBox::~MassageBox() {}

void MassageBox::hide()
{
	isVisible = false;
}

void MassageBox::show()
{
	isVisible = true;
}

void MassageBox::draw(Graphics& g, int x, int y, size_t size)
{
	panel.setWidth(21);
	panel.setHeight(5);
	panel.addControlsToVector(&label);

	if (isVisible) {
		panel.draw(g, x, y, size);
	}
}


void MassageBox::buttonEvent() 
{
	if (isVisible == FALSE) 
	{
		isVisible = TRUE;
	}
	else
	{
		isVisible = FALSE;
	}
}