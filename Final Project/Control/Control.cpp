#include "Control.h"



Control::Control(int _width) : 
	width(_width), isFocused(false), ifFocusable(true), visible(true), height(1), layer(0){
	setBorder(BorderType::None);
	setLocation({ 0, 0 });
	width += 2;
	height += 2;
	background = BackgroundColor::Black;
	foreground = ForegroundColor::Green;
}

void Control::show(){
	visible = true;
	ifFocusable = true;
}
void Control::hide(){
	visible = false;
	ifFocusable = false;
}

int Control::getLayer() {
	return layer;
}

void Control::setLayer(int l) {
	layer = l;
}

void Control::focus(){
	isFocused = true;
}
void Control::unfocus(){
	isFocused = false;
}
void Control::setForeground(ForegroundColor color){
	foreground = color;
}
void Control::setBackGround(BackgroundColor color){
	background = color;
}

ForegroundColor Control::getForeground(){
	return foreground;
}
BackgroundColor Control::getBackGround(){
	return background;
}

void Control::setBorder(BorderType type){
	borderType = type;
}

BorderType Control::getBorderType(){
	return borderType;
}
char Control::getBorderTypeHorizontal(){
	switch (getBorderType())
	{
	case BorderType::Single:
			return 196;
			break;
	case BorderType::Double:
		return 205;
		break;
	default:
		return NULL;
		break;
	}
}
char Control::getBorderTypeVertical(){
	switch (getBorderType())
	{
	case BorderType::Single:
		return 179;
		break;
	case BorderType::Double:
		return 186; // ' || '
		break;
	default:
		return NULL;
		break;
	}
}

vector<int> Control::getBorderTypeCorners(){
	switch (getBorderType())
	{
	case BorderType::Single:
		return { 218, 191 , 192, 217};
		break;
	case BorderType::Double:
		return{ 201, 187, 200 , 188}; 
		break;
	default:
		return{ 0 , 0, 0, 0};
		break;
	}
}
void Control::setLocation(COORD coord){
	location = coord;
	bodyLocation = { coord.X + 1, coord.Y + 1 };
}

COORD Control::getLocation(){
	return location;
}
void Control::draw(Graphics &graphics, int x, int y, size_t w){
	if (isFocus()) {
		graphics.setForeground(graphics.convertToColor(ForegroundColor::White));
	} else {
		graphics.setForeground(graphics.convertToColor(getForeground()));
	}
	graphics.setBackground(graphics.convertToColor(getBackGround()));
	string str(width, getBorderTypeHorizontal());
	vector<int> corners = getBorderTypeCorners();
	str[0] = corners[0];
	str[width - 1] = corners[1];
	graphics.write(getLeft(), getTop(), str);
	
	for (int i = 0; i < height - 1; i++){
		string strv(width, ' ');
		strv[0] = getBorderTypeVertical();
		strv[width-1] = getBorderTypeVertical();
		graphics.write(getLeft(), (getTop() + 1 ) + i, strv);
	}
	str[0] = corners[2];
	str[width - 1] = corners[3];
	graphics.write(location.X, location.Y + (height - 1), str);
	graphics.resetColors();
}

void Control::mousePressed(short x, short y, bool isLeft){

	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth())) return;
	if (y < this->getTop() || (y > this->getTop() + this->getHeight())) return;

	Control::setFocus(this);
}

bool Control::canGetFocus(){
	return ifFocusable;
}
bool Control::validSpace(Control* c){

	if ((c->getLeft() + c->getWidth()) < getLeft() ||
		(getLeft() + getWidth()) < c->getLeft()) {
		return true;
	}
	else if ( (c->getTop() + c->getHeight() ) > getTop() ||
		(getTop() + getHeight()) < c->getTop()) {
		return true;;
	}
	return false;
}
bool Control::isFocus(){
	return isFocused;
}
bool Control::isVisible(){
	return visible;
}
short Control::getLeft(){
	return location.X;
}
short Control::getTop(){
	return location.Y;
}

short Control::getBodyLeft(){
	return bodyLocation.X;
}
short Control::getBodyTop(){
	return bodyLocation.Y;
}

int Control::getWidth(){
	return width;
}
int Control::getHeight(){
	return height;
}

void Control::setHeight(int h) {
	height = h;
}

void Control::setWidth(int w) {
	width = w;
}

	
void Control::setFocus(Control* c){
	if (currentFocused != NULL)
		currentFocused->unfocus();
	currentFocused = c;
	c->focus();
}

Control* Control::getFocus(){
	return currentFocused;
}


Control::~Control(){

}