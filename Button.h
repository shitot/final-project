#pragma once
#include "../Common/Label.h"


class Button : public Control {
	string value;
	int width;
	int height;
	bool isClicked;
	vector <Control*> events;
public:
	Button(Border* , short , short , string);
	void mousePressed(int, int, bool);
	int getWidth();
	void setEvent(Control*);
	void draw(Graphics&, int, int, size_t);
	bool getFocus() { return FALSE; };
	~Button();
};