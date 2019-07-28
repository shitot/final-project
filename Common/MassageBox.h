#pragma once
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class MassageBox : public Control
{
public:
	MassageBox(short _left, short _top, string message);

	void draw(Graphics& g, int x, int y, size_t size);
	bool canGetFocus() { return TRUE; };
	void onFocus(bool flag);
	void hide();
	void show();
	bool getVisible() {return isVisible;}
	void buttonEvent();

	~MassageBox();

private:
	Label label;
	Panel panel;
	bool isVisible = FALSE;
	bool focus;
};
