#include "Message_Box.h"

Message_Box::Message_Box(int bord, short x, short y, COORD cor, string str) {
	this->borderType = bord;
	this->left = x;
	this->top = y;
	this->cord = cor;
	this->messageBoxValue = str;
	messageBoxBtns.push_back(new Button(1, x + 1, y + cor.Y, { 8,2 }, "Cancel"));
	messageBoxBtns.push_back(new Button(1, x + 11, y + cor.Y, { 8,2 }, "OK"));
}

void Message_Box::setMessageBoxValue(string str) {
	this->messageBoxValue = str;
}

string Message_Box::getMessageBoxValue() {
	return this->messageBoxValue;
}

void Message_Box::draw(Graphics & g, int x, int y, size_t z) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	switch (borderType)
	{
	case 0:
		break;
	case 1:
		border.drawSingleBorder(x, y, cord);	// drawing the numeric box
		break;
	case 2:
		border.drawDoubleBorder(x, y, cord);	// drawing the numeric box
		break;
	default:
		break;
	}
	SetConsoleCursorPosition(out, { (SHORT)(x + 1), (SHORT)(y + 1) });
	cout << this->messageBoxValue;
	for (int i = 0; i < this->messageBoxBtns.size(); i++)
		this->messageBoxBtns[i]->draw(g, x + 2 + 10 * i, y + this->cord.Y - 4, z);
}

bool Message_Box::canGetFocus() { return false; }