#include "shop.h"


// Shop Private Method
void Shop::ListTop()
{
	std::cout << "\t품목\t\t남은 개수\t\t가격\n";
}

void Shop::title()
{
	return;
}

void Shop::menu()
{
	std::cout << "l. 판매 품목 리스트 출력\t";
	std::cout << "i. 계정 정보 출력\n";
	std::cout << "q. 로그아웃\n";
}

void Shop::displayThingsList(Seller* seller)
{
	ListTop();
}

void Shop::displayThingsList(Customer* customer)
{
	ListTop();
}