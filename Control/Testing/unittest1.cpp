
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NumericBox/NumericBox.h"
#include "../TextBox/TextBox.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/*
struct GraphicsMock : Graphics{
	GraphicsMock() :Graphics(), _screen(25 * 80, L'\0') {}
	void moveTo(int x, int y){ _cursorX = x; _cursorY = y; }
	void write(string s){
		for (size_t i = 0; i < s.size(); ++i){
			_screen[_cursorY * 80 + _cursorX + i] = s[i];
		}
	}
	void write(int x, int y, string s) { moveTo(x, y); write(s); }
	string getStringAt(int x, int y, size_t length) {
		string s;
		for (; length; ++x, --length)
			s += _screen[y * 80 + x];
		return s;
	}
	void clearAt(int x, int y, size_t length) {
		for (; length; ++x, --length) _screen[y * 80 + x] = '\0';
	}
	bool isClear() {
		for (size_t i = 0; i < _screen.size(); ++i)
			if (_screen[i])
				return false;
		return true;
	}
private:
	vector<char> _screen;
	int _cursorX, _cursorY;
	
};
*/

namespace Testing
{		
	TEST_CLASS(UnitTest1)
	{
		
	public:
		NumericBox *box = new NumericBox(30, 10, 50);
		TEST_METHOD(setHeightCheck)
		{
			Assert::AreEqual(5, box->getHeight(), L"message");
			box->setHeight(6);
			Assert::AreEqual(6, box->getHeight(), L"message");
		}
		TEST_METHOD(setValueCheck)
		{
			Assert::AreEqual(10, box->getValue(), L"message");
			box->setValue(13);
			Assert::AreEqual(13, box->getValue(), L"message");
		}
		TEST_METHOD(setWidthCheck)
		{
			Assert::AreEqual(32, box->getWidth(), L"message");
			box->setWidth(20);
			Assert::AreEqual(20, box->getWidth(), L"message");
		}
		TEST_METHOD(setPositionCheck)
		{
			Assert::AreEqual(0, (int)box->getTop(), L"message");
			Assert::AreEqual(0, (int)box->getLeft(), L"message");
			Assert::AreEqual(1, (int)box->getBodyTop(), L"message");
			Assert::AreEqual(1, (int)box->getBodyLeft(), L"message");
			box->setLocation({ 2,2 });
			Assert::AreEqual(2, (int)box->getTop(), L"message");
			Assert::AreEqual(2, (int)box->getLeft(), L"message");
			Assert::AreEqual(3, (int)box->getBodyTop(), L"message");
			Assert::AreEqual(3, (int)box->getBodyLeft(), L"message");
		}
		/*
		TEST_METHOD(testDraw)
		{
			GraphicsMock g;
			TextBox textBox(10);
			textBox.setValue("Hello");
			textBox.setLocation({ 0,0 });
			textBox.draw(g, 0, 0, 0);
			Assert::AreEqual("Hello", g.getStringAt(3, 3, 5).c_str());
			g.clearAt(0, 0, 10);
			Assert::IsTrue(g.isClear());
		}*/
	};
}