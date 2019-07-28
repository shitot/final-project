#include "CheckBox.h"
#include <iostream>

using namespace std;

CheckBox::CheckBox(short CBleft, short CBtop, string CBvalue) :Control(CBleft, CBtop), value(CBvalue) , isSelected(FALSE) 
{}

void CheckBox::changeBackToWhite()
{
	bgColor = Color::White;
	fgColor = Color::Black;
}

void CheckBox::changeBackToBlack()
{
	bgColor = Color::Black;
	fgColor = Color::White;
}

bool CheckBox::getIsSelected()
{
	return isSelected;
}

void CheckBox::setIsSelected()
{
	if (!isSelected)
	{
		isSelected = TRUE;
	}
	else
	{
		isSelected = FALSE;
	}
}
void CheckBox::draw(Graphics & g, int x, int y, size_t z)
{

	g.moveTo(x, y);
	g.setBackground(bgColor);
	g.setForeground(fgColor);


	cout << '\xDA' << '\xC4'<< '\xC4' << '\xBF';
	for (int i = 0; i < value.size() + 1 ; i++) {
		cout << ' ';
	}

	g.moveTo(x, y + 1);
	cout << '\xB3' << ' ' << ' ' << '\xB3' <<' ';

	g.moveTo(x, y + 2);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xD9';

	for (int i = 0; i < value.size() + 1; i++) {
		cout << ' ';
	}

	if (isSelected)
	{
		g.write(x + 1, y + 1 , "X");
	}

	g.moveTo(x + 5, y + 1);
	g.write(value);
}

CheckBox::~CheckBox()
{}