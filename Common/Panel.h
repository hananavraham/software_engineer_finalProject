#include "../Common/Control.h"
#include <string>

using namespace std;

class Panel : public Control
{
private:
	vector<Control*> items;
	int currentFocus;

public:
	Panel(int borderType, short x, short y, COORD cord);
	void setCurrentFocus(int);
	int getCurrentFocus();
	virtual void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
	virtual void Add(Control* control);

	void getAllControls(vector<Control*>* controls);

	void mousePressed(int x, int y, bool isLeft) {};

	virtual bool canGetFocus();

	Control* getFocus();
	void setFocus(Control& control);

	virtual Control* GetIndex(int i);

	short getLeft();
	short getTop();
};