#pragma once
#include "Control.h"
#include "../Common/RadioBox.h"
class RadioList : public Control
{

private:
	vector<RadioBox*> radioBoxs;
	vector<COORD> checkBoxCoord;
	int currentCboxIndex;
	int selectedIndex;
	int lastSelected;
	bool focus;

public:
	

	RadioList(Border* border, short _left, short _top, vector<string> _values);

	void draw(Graphics& g, int x, int y, size_t z);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter, Graphics & g);
	bool canGetFocus() { return TRUE; };
	bool isListObj() { return TRUE; }
	bool getIsInLastChild();
	void onFocus(bool flag);

	~RadioList();
};

