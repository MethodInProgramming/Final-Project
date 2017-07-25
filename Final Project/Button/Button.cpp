#include "Button.h"

Button::Button(int width, string text) : Control(width), text(text), clickable(true), listener(&EmptyListener()){

}

void Button::draw(Graphics& graphics, int x, int y, size_t layer){
	if (getLayer() != layer) return;
	Control::draw(graphics, x, y, layer);
	graphics.setBackground(graphics.convertToColor(getBackGround()));
	graphics.setForeground(graphics.convertToColor(getForeground()));
	graphics.write(getBodyLeft(), getBodyTop(), getValue());
	graphics.resetColors();
}

void Button::mousePressed(short x, short y, bool isLeft){
	if (clickable && 
		x > getLeft() && 
		x < getLeft() + getWidth() &&
		y > getTop() && 
		y < getTop() + getHeight()){

		listener->mousePressed(*this, x, y, isLeft);
	}
}

void Button::keyDown(WORD click, CHAR chr){
	if (click == VK_RETURN) {
		//add the same functional like mouse press
		listener->mousePressed(*this, 0, 0, true);
	}
}

void Button::setValue(string value){
	text = value;
}
void Button::addListener(MouseListener& listnr){
	listener = &listnr;
}
string Button::getValue(){
	return text;
}

Button::~Button(){
	free(listener);
}
