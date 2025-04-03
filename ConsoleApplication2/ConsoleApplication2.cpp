#include "shop.h"


int main()
{
	Customer test("1", "2", "3");

	Shop s;
	s.displayThingsList(test);
	return 0;
}
