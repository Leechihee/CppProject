#include "shop.h"
#include <windows.h>

// Shop Private Method
void Shop::ListTop()
{
	system("cls");
	for (int i = 0;i < 60;i++)
		std::cout << '=';
	std::cout << "\n\tǰ��\t\t���� ����\t\t����\n";
}

void Shop::displayList()
{
	int index;
	for (index = 0;index < thingsList.size();index++)
	{
		std::cout << index + 1 << ". ";
		thingsList[index].thingsDisplay();
	}
	for (;index < max;index++)
	{
		std::cout << index + 1 << ". ";
		std::cout << '\t' << "----" << "\t\t  " << "----" << "\t\t\t" << "----" << '\t' << std::endl;
	}
	for (int i = 0;i < 60;i++)
		std::cout << '=';
	std::cout << std::endl;
}

// Shop Public Method
void Shop::title()
{
	return;
}

void Shop::menu()
{
	std::cout << "a. �Ǹ� ǰ�� ����Ʈ ���\t";
	std::cout << "b. ���� ���� ���\n";
	std::cout << "q. �α׾ƿ�\n";
}

void Shop::displayThingsList(Seller seller)
{
	ListTop();
	displayList();
	std::cout << std::endl;
	std::cout << "    a.ǰ�� �߰�/����\tb.ǰ�� ����\tq.������\n";
}

bool Shop::pushThingsToList(const Things& things)
{
	if (thingsList.size() < 10)
	{
		thingsList.push_back(things);
		return true;
	}
	else
		return false;
}

void Shop::displayThingsList(Customer customer)
{
	ListTop();
	displayList();
	std::cout << std::endl;
	std::cout << "\ta.���� �����ϱ�\t\tq.������\n";
}