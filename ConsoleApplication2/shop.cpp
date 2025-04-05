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
    system("cls");
    std::string S[] = {
        " ������  ",
        "��           ",
        "��           ",
        " ������  ",
        "          �� ",
        "          �� ",
        "������   "
    };
    std::string H[] = {
        "��        ��  ",
        "��        ��  ",
        "��        ��  ",
        "�������  ",
        "��        ��  ",
        "��        ��  ",
        "��        ��  "
    };
    std::string O[] = {
        " ������  ",
        "��        ��  ",
        "��        ��  ",
        "��        ��  ",
        "��        ��  ",
        "��        ��  ",
        " ������   "
    };
    std::string P[] = {
        " ������  ",
        "��       ��  ",
        "��       ��  ",
        "������   ",
        "��           ",
        "��           ",
        "��           "
    };

    // �� ���ڸ� ���
    for (int i = 0; i < 7; i++) {
        std::cout << S[i] << "  " << H[i] << "  " << O[i] << "  " << P[i] << std::endl;
    }
    std::cout << std::endl;
}

void Shop::menu()
{
    title();
	std::cout << "a. �Ǹ� ǰ�� ����Ʈ ���\t";
	std::cout << "b. ���� ���� ���\n";
	std::cout << "q. �α׾ƿ�\n";
}

// Seller Option Method
void Shop::displayThingsList(Seller seller)
{
	ListTop();
	displayList();
	std::cout << std::endl;
	std::cout << "    a.ǰ�� �߰�/����\tb.ǰ�� ����\tq.������\n";
}

bool Shop::pushThingsToList(const Things& things, const int& index)
{
	if (thingsList.empty())
		thingsList.push_back(things);
	else if (index < 1 || index > thingsList.size() || thingsList.size() >= max)
		return false;
	else
		thingsList.insert((thingsList.begin() + index - 1), things);
	return true;
}

bool Shop::popThingsToList(const int& index)
{
	if (index < 1 || index>thingsList.size())
		return false;
	thingsList.erase(thingsList.begin()+index-1);
	return true;
}

// Customer Option Method
void Shop::displayThingsList(Customer customer)
{
	ListTop();
	displayList();
	std::cout << std::endl;
	std::cout << "\ta.���� �����ϱ�\t\tq.������\n";
}