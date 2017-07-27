#include <string>
#include "../Panel/Panel.h"
#include "../CheckList/CheckList.h"
#include "../ComboBox/ComboBox.h"
#include "../Graphics/Graphics.h"
#include "../TextBox/TextBox.h"
#include "../RadioList/RadioList.h"
#include "../EventHandler/EventHandler.h"
#include "../NumericBox/NumericBox.h"
#include "../MessegeBox/MsgBox.h"

using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Control& b, short x, short y, bool isLeft)
	{
		_c.show();
		Control::setFocus(&_c);
	}
private:
	Control &_c;
};


int main(void){

	Label lName(20, "First Name: ");
	Label lLastName(20, "Last Name: ");
	Label lCity(20, "Company:");
	Label lSex(20, "Sex:");
	Label lFavoritesMovies(20, "Favorive Movies: ");
	Label lAge(20, "Age:");
	TextBox tName(20);
	tName.setValue("Gal");
	tName.setBorder(BorderType::Double);
	TextBox tLastName(25);
	tLastName.setValue("Amitai");
	tLastName.setBorder(BorderType::Double);
	ComboBox cGenre(20, { "DC", "Marvel", "WB","Sony","Paramount" });
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
	main.addControl(&msgBox, 16, 16);
	main.addControl(&lName, 2, 3);
	main.addControl(&lLastName, 2, 6);
	main.addControl(&lCity, 2, 9);
	main.addControl(&lSex, 2, 14);
	main.addControl(&lFavoritesMovies, 1, 21);
	main.addControl(&lAge, 1, 32);
	main.addControl(&tName, 25, 2);
	main.addControl(&tLastName, 25, 5);
	main.addControl(&cGenre, 25, 8);
	main.addControl(&rSex, 25, 13);
	main.addControl(&clInterests, 25, 21);
	main.addControl(&nAge, 25, 32);

	main.addControl(&bSubmit, 27, 39);
	Control::setFocus(&tName);
	EventHandler Handler;
	Handler.run(main);
	return 0;

}


//Created by Or Adar , Yossi Efraim, Gal Amitai and Uri Portnoy
//Method in Software Engineering
//Dr. Rash Amit, Mr. Algawi Asaf