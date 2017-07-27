#include "NumericBox.h"



NumericBox::NumericBox(int width, int min, int max):Panel(5,width)
{
	value = min;
	MinusListener* minusListener = new MinusListener(*this);
	PlusListener* plusListener = new PlusListener(*this);
	Button *minusBtn = new Button(1,"-");
	minusBtn->addListener(*minusListener);
	Label *labelVal = new Label( width - 8 ,to_string(min));
	labelVal->setForeground(getForeground());
	Button *plusBtn = new Button(1,"+");
	plusBtn->addListener(*plusListener);
	
	addControl(minusBtn, getBodyLeft(), getBodyTop());
	this->min = min;
	addControl(labelVal, getBodyLeft() + minusBtn->getWidth(), getBodyTop());
	addControl(plusBtn, labelVal->getLeft() + labelVal->getWidth(), getBodyTop());
	this->max = max;
}


void NumericBox::setValue(int val) {
	
	if ( val < min || val >max) return;
	else {
		static_cast<Label*>(controls[1])->setValue(to_string(val));
		string num1 = to_string(val);
	}
};
int NumericBox::getValue() {	
	string val = static_cast<Label*>(controls[1])->getValue();
	int size = val.length();
	string num;
	for (int i = 0; i < size; i++) {
		if (val.at(i) != '\0') {
			num += val.at(i);
		}
	}
	return stoi(num);
};
