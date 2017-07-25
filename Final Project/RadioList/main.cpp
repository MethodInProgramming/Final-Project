#include "RadioList.h"
#include "../EventEngine/EventEngine.h"

int main(VOID) {
	Panel p(25, 50);
	p.setLocation({ 10, 10 });
	p.setBorder(BorderType::Single);
	vector<string> strings;
	strings.push_back("aba");
	strings.push_back("fsdf");
	strings.push_back("khj");
	strings.push_back("werewr");
	RadioList cName(14, 30, strings);
	cName.setBorder(BorderType::Double);
	Control::setFocus(&cName);
	cName.setBackGround(BackgroundColor::Green);
	//cName.setForeground(ForegroundColor::Blue);
	p.addControl(&cName, 15, 15);
	EventEngine engine;
	engine.run(p);
	return 0;
}