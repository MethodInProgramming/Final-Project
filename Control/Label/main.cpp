#include "Label.h"
#include "../EventEngine/EventEngine.h"

using namespace std;

int main(void) {

	Label label(20, "Or Adar");
	label.setLocation({ 20, 30 });
	EventEngine engine;
	engine.run(label);
	return 0;
}