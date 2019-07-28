#pragma once
#include "Control.h"
class ComboBox :public Control
{
private:
	vector<string> values;
	string valueToShow;
	bool isOpen;
	int currentIndex;
	int width;
	int selectedIndex;
public:
	ComboBox(Border* _border, short _left, short _top, vector<string> _values);
	void draw(Graphics& g, int x, int y, size_t size);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater, Graphics & g);
	bool canGetFocus() { return TRUE; };
	bool isListObj() { return TRUE; }
	int getWidth() { return width; };
	bool getIsInLastChild();
	void onFocus(bool flag);

	~ComboBox();
};