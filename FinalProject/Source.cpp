#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Label.h"
#include "../Common/CheckList.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/NumericBox.h"
#include "../Common/TextBox.h"
#include "../Common/RadioList.h"
#include "../Common/MassageBox.h"
#include "../Common/ComboBox.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	EventEngine eventEngine;

	CheckList checkList(new LineBorder() , 2, 2, { "City central" , "Free wifi"  , "Parking" ,  "Breakfast" });

	RadioList radioList(new LineBorder(), 28, 2, { "England" , "France"  , "Spain" ,  "Germany" });

	ComboBox comboBox(new LineBorder(), 23, 17, { "1 star" , "2 star"  , "3 star" ,  "4 star" });

	Panel panel(new LineBorder(), 1, 1);

	panel.setWidth(60);
	panel.setHeight(30);

	NumericBox numericBox(new LineBorder(), 2, 17);

	TextBox textBox(new LineBorder(), 2, 20, 20, 4);

	MassageBox messageBox(20, 8, "Happy Vacation!");
	
	Button button(new DoubleBorder(), 2, 23, "button");
	Button submit(new LineBorder(), 10, 23, "Submit");

	submit.setEvent(&messageBox);
	panel.addControlsToVector(&checkList);
	panel.addControlsToVector(&radioList);
	panel.addControlsToVector(&textBox);
	panel.addControlsToVector(&numericBox);
	panel.addControlsToVector(&button);
	panel.addControlsToVector(&submit);
	panel.addControlsToVector(&messageBox);
	panel.addControlsToVector(&comboBox);


	Control* firstFocus;
	if (firstFocus = panel.getFirstControl())
	{
		Control::setFocus(*firstFocus);
	}
	
	eventEngine.run(panel);
	
}