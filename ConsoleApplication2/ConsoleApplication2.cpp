#include "shop.h"


int main()
{
	Customer test("1", "2", "3");

	Shop s;
	s.displayThingsList(test);
	s.pushThingsToList(Things("칫솔", 100, 1000));
	s.displayThingsList(test);
	s.pushThingsToList(Things("핸드폰", 50, 750));
	s.displayThingsList(test);
	s.popThingsToList();
	s.displayThingsList(test);
	return 0;
}
