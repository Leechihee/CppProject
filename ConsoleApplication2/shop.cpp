#include "shop.h"


// Shop Private Method
void Shop::ListTop()
{
	std::cout << "\tǰ��\t\t���� ����\t\t����\n";
}

void Shop::title()
{
	return;
}

void Shop::menu()
{
	std::cout << "l. �Ǹ� ǰ�� ����Ʈ ���\t";
	std::cout << "i. ���� ���� ���\n";
	std::cout << "q. �α׾ƿ�\n";
}

void Shop::displayThingsList(Seller* seller)
{
	ListTop();
}

void Shop::displayThingsList(Customer* customer)
{
	ListTop();
}