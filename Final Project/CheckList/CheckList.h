#pragma once

#include "../Panel/ListPanel.h"
#include "../Button/ButtonItem.h"

class CheckList : public ListPanel
{
	struct SelectListener : public MouseListener{
		SelectListener(Control& c) : _c(c){}
		void mousePressed(Control& b, short x, short y, bool isLeft){
			CheckList& tmp = static_cast<CheckList&>(_c);
			int index = static_cast<ButtonItem&>(b).getIndex();
			tmp.selectIndex(index);
			tmp.switchFocus(index);
		}
	private:
		Control& _c;
	};
protected:
	//we need to override only the enter click
	void onEnterKey();
public:
	CheckList(int height, int width, vector<string> options); // checklist constructor
	vector<size_t> getSelectedIndices(); 
	void selectIndex(size_t index);
	void disableIndex(size_t index);
	void mousePressed(short, short, bool);
};

