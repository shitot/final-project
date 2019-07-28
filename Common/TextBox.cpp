#include "TextBox.h"
#include <iostream>
#include <string>

using namespace std;


TextBox::TextBox() {}

TextBox::TextBox(Border *_border, short _left, short _top, int _width, int _height) : Control(_left, _top, _border), width(_width), height(_height), cursor(0), focus(FALSE), value()
{
}


void TextBox::onFocus(bool flag)
{
	focus = flag;

}


void TextBox::draw(Graphics & g, int x, int y, size_t size)
{

	if (focus)
	{

		this->border->drawBorder(g, x, y, this->width, this->height);
		g.write(x + 1, y + 1, value);
		g.moveTo(cursor + (left + 1), top + 1);
		g.setCursorVisibility(TRUE);
		g.write("_");
	}
	else
	{
		this->border->drawBorder(g, x, y, this->width, this->height);
		g.setCursorVisibility(FALSE);
		g.write(x + 1, y + 1, value);
	}

}

void TextBox::keyDown(int keyCode, char character, Graphics & g)
{
	int stringSize = static_cast<int>(value.size());

	g.moveTo(static_cast<int>(value.size()) + (left + 1), top + 1);
	if (character > 0)
	{
		if ((width - 2) > stringSize && (character >= 65 && character <= 90 || character >= 97 && character <= 122 || character >= 48 && character <= 57 || character == 32))
		{
			if (cursor < stringSize)
			{
				if (character == 32)
				{
					value.replace(value.begin() + cursor, value.end() - (stringSize - cursor), 1, character);
				}
				else
				{
					value.replace(value.begin() + cursor, value.end() - (stringSize - cursor), 1, character);
					cursor++;
				}
			}
			else
			{
				value.push_back(character);
				cursor = static_cast<int>(value.size());
			}

		}
	}
	else
	{
		switch (keyCode)
		{
		case VK_DELETE:
			if (cursor > 0)
			{
				value.erase(value.begin() + (cursor - 1));
				--cursor;
			}
			break;
		case VK_BACK:
			if (cursor > 0)
			{
				value.erase(value.begin() + (cursor - 1));
				--cursor;
			}
		case VK_LEFT:
			if (cursor > 0)
			{
				--cursor;
			}
			break;
		case VK_NUMPAD4:
			if (cursor > 0)
			{
				--cursor;
			}
		case VK_RIGHT:
			if (cursor < stringSize)
			{
				++cursor;
			}
			break;
		case VK_NUMPAD6:
			if (cursor < stringSize)
			{
				++cursor;
			}
			break;
		}
	}
}


void TextBox::mousePressed(int x, int y, bool isLeft)
{
	int stringSize = static_cast<int>(value.size());

	if (y == top && (x > left && x < (left + width - 1)))
	{
		if (x > stringSize)
		{
			cursor = stringSize;
		}
		else
		{
			cursor = (x - (left + 1));
		}
	}
}

TextBox::~TextBox() {}
