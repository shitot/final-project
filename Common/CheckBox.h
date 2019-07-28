#pragma once
#include "Control.h"


class CheckBox : public Control
{
	string value;
	bool isSelected;

public:
	
	CheckBox(short, short, string );
	void changeBackToWhite();
	void changeBackToBlack();
	bool getIsSelected();
	void setIsSelected();
	void draw(Graphics&, int, int, size_t);
	bool getFocus() { return TRUE; };
	~CheckBox();
};