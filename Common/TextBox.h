#pragma once
#include "Control.h"
#include "../Common/Border.h"


class TextBox : public Control
{

private:

	int width;
	int height;
	int cursor;
	bool focus;
	string value;


public:

	TextBox();
	TextBox(Border *_border, short _left, short _top, int _width, int _height);
	~TextBox();
	void onFocus(bool flag);
	bool canGetFocus() { return TRUE; };
	void draw(Graphics& g, int x, int y, size_t size);
	void keyDown(int keyCode, char character, Graphics & g);
	void mousePressed(int x, int y, bool isLeft);
	int getWidth() { return width; };
};