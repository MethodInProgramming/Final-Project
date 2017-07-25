#include <string>
#include "../Panel/Panel.h"
#include "../CheckList/CheckList.h"
#include "../ComboBox/ComboBox.h"
#include "../Graphics/Graphics.h"
#include "../TextBox/TextBox.h"
#include "../RadioList/RadioList.h"
#include "../EventEngine/EventEngine.h"
#include "../NumericBox/NumericBox.h"
#include "../MessegeBox/MsgBox.h"

using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Control& b, short x, short y, bool isLeft)
	{
		//Panel::toggleMsgBox();
		_c.show();
		Control::setFocus(&_c);
	}
private:
	Control &_c;
};


int main(void){

	Label lName(20, "First Name: ");
	//FName.setText("Name: ");

	Label lLastName(20, "Last Name: ");
	//lLastName.setValue("Last Name: ");
	Label lCity(20, "Company:");
	//lCity.setValue("City:");
	Label lSex(20, "Sex:");
	//lSex.setValue("Sex:");
	Label lFavoritesMovies(20, "Favorive Movies: ");
	//lFavoritesMovies.setValue("Interests:");
	Label lAge(20, "Age:");
	//lAge.setValue("Age:");
	TextBox tName(20);
	tName.setValue("Gal");
	tName.setBorder(BorderType::Double);
	TextBox tLastName(25);
	tLastName.setValue("Amitai");
	tLastName.setBorder(BorderType::Double);
	ComboBox cGenre(20, { "DC", "Marvel", "WB" });
	cGenre.setSelectedIndex(1);
	cGenre.setBorder(BorderType::Single);
	RadioList rSex(8, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	CheckList clInterests(11, 20, { "Captain America", "Batman", "Spiderman" });
	clInterests.selectIndex(1);
	clInterests.setBorder(BorderType::Double);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(28);
	nAge.setBorder(BorderType::Single);

	MsgBox msgBox(15, 20);
	msgBox.hide();
	msgBox.setBorder(BorderType::Double);
	msgBox.setBackGround(BackgroundColor::White);
	msgBox.setForeground(ForegroundColor::Cyan);

	MyListener* listener = new MyListener(msgBox);
	Button bSubmit(10, "Submit");
	bSubmit.addListener(*listener);
	bSubmit.setBorder(BorderType::Double);


	Panel main(50, 70);
	main.addControl(&msgBox, 15, 15);
	main.addControl(&lName, 1, 2);
	main.addControl(&lLastName, 1, 5);
	main.addControl(&lCity, 1, 8);
	main.addControl(&lSex, 1, 13);
	main.addControl(&lFavoritesMovies, 1, 21);
	main.addControl(&lAge, 1, 32);
	main.addControl(&tName, 25, 2);
	main.addControl(&tLastName, 25, 5);
	main.addControl(&cGenre, 25, 8);
	main.addControl(&rSex, 25, 13);
	main.addControl(&clInterests, 25, 21);
	main.addControl(&nAge, 25, 32);

	main.addControl(&bSubmit, 1, 35);
	Control::setFocus(&tName);
	EventEngine engine;
	engine.run(main);
	return 0;

}