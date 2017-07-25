#pragma once

#include "Button.h"
#include <string>

using namespace std;

class ButtonItem : public Button
{
	string chkedText;
	bool isCheck;
	size_t index;
public:
	ButtonItem(string text, int width, size_t index);
	bool isChecked();
	void toggle();
	//void mousePressed(short, short, bool);
	void draw(Graphics &graphics, int x, int y, size_t w);
	size_t getIndex();
	~ButtonItem();
};

