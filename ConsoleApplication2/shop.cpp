#include "shop.h"
#include <windows.h>
#include <conio.h>

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
        "  ������  ",
        " ��           ",
        " ��           ",
        "  ������  ",
        "           �� ",
        "           �� ",
        " ������   "
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

    for (int i = 0;i < 60;i++)
        std::cout << '=';
    std::cout << std::endl;

    // �� ���ڸ� ���
    for (int i = 0; i < 7; i++) {
        std::cout << S[i] << "  " << H[i] << "  " << O[i] << "  " << P[i] << std::endl;
    }

    for (int i = 0;i < 60;i++)
        std::cout << '=';
    std::cout << std::endl;
}

void Shop::menu()
{
    title();
	std::cout << "\n      a. �Ǹ� ǰ�� ����Ʈ ���";
	std::cout << "      b. ���� ���� ���\n";
	std::cout << "\n      q. �α׾ƿ�\n";
}

int Shop::tryLogin()
{
	while (true)
	{
		title();
		std::cout << "\n    a. �����ڰ������� ����\tb. �Һ��ڰ������� ����\n\n    q. ������";
		switch (_getch())
		{
		case 'a':
		case 'A':
			return 1;
		case 'b':
		case 'B':
			return 2;
		case 'q':
		case 'Q':
			return 3;
		default:
			continue;
		}
	}
}

int Shop::listSize(void)
{
	return thingsList.size();
}

bool Shop::listFull(void)
{
	return thingsList.size() >= max;
}

// Seller Option Method
void Shop::displayThingsList(Seller seller)
{
	ListTop();
	displayList();
	std::cout << std::endl;
	std::cout << "      a.ǰ�� �߰�/����\t  b.ǰ�� ����\t  q.������\n";
}

bool Shop::pushThingsToList(const Things& things,int index)
{
	if (thingsList.empty())
		thingsList.push_back(things);
	else if (index < 1)
	{
		std::cout << "\n  1������ ���� ��ȣ�� �Է��Ͽ� �ڵ����� 1������ �߰��մϴ�\n\n";
		thingsList.insert((thingsList.begin()), things);
		system("pause");
	}
	else if (index > thingsList.size())
	{
		std::cout << "\n ���������� ū ��ȣ�� �Է��Ͽ� �ڵ����� ���������� �߰��մϴ�\n\n";
		thingsList.push_back(things);
		system("pause");
	}
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

bool Shop::thingsModify(const int& index, const int& amount)
{
	if (index<1 || index > thingsList.size() || index>max)
		return false;
	thingsList[index - 1].setAmount(amount);
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

bool Shop::buyTheThings(const int& index, const int& count)
{
	if (index < 1 || index > thingsList.size() || index > max)
		return false;
	if (thingsList[index - 1] -= count)
		return true;
	else
	{
		thingsList.erase(thingsList.begin() + index - 1);
	}
}