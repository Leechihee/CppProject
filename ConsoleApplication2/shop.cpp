#include "shop.h"
#include <windows.h>
#include <conio.h>
#include <iomanip>

// Shop Private Method
void Shop::ListTop()
{
	system("cls");
	std::cout << std::string(60, '=') << std::endl;
	std::cout << std::setw(4) << " "; // 번호 자리 확보

	std::cout << std::left << std::setw(18) << "품목";

	std::string centerHeader = "남은 개수";
	int centerPadding = (18 - centerHeader.length()) / 2;
	std::cout << std::string(centerPadding, ' ') << centerHeader << std::string(18 - centerPadding - centerHeader.length(), ' ');

	std::cout << std::right << std::setw(18) << "가격" << std::endl;
}

void Shop::displayList()
{
	int index;
	for (index = 0; index < max; index++)
	{
		std::cout << std::setw(3) << index + 1 << ". ";

		if (index < thingsList.size())
		{
			thingsList[index].thingsDisplay();
		}
		else
		{
			// 빈 칸 출력
			std::cout << std::left << std::setw(18) << "----";

			std::string mid = "----";
			int midPadding = (18 - mid.length()) / 2;
			std::cout << std::string(midPadding, ' ') << mid << std::string(18 - midPadding - mid.length(), ' ');

			std::cout << std::right << std::setw(18) << "----" << std::endl;
		}
	}

	std::cout << std::string(60, '=') << std::endl;
}

// Shop Public Method
void Shop::title()
{
	system("cls");

	std::cout << std::string(60, '=') << std::endl;

	std::cout << R"(
            ######   #     #    #####    ######  
           #         #     #   #     #   #     # 
           #         #     #   #     #   #     # 
            #####    #######   #     #   ###### 
                 #   #     #   #     #   #      
                 #   #     #   #     #   #      
           ######    #     #    #####    #      
)" << std::endl;

	std::cout << std::string(60, '=') << std::endl;
}

void Shop::menu()
{
    title();
	std::cout << "\n      a. 판매 품목 리스트 출력";
	std::cout << "      b. 계정 정보 출력\n";
	std::cout << "\n      q. 로그아웃\n";
}

int Shop::tryLogin()
{
	while (true)
	{
		title();
		std::cout << "\n    a. 관리자계정으로 입장\tb. 소비자계정으로 입장\n\n    q. 나가기";
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
	std::cout << "      a.품목 추가/수정\t  b.품목 제거\t  q.나가기\n";
}

bool Shop::pushThingsToList(const Things& things,int index)
{
	if (thingsList.empty() || index == thingsList.size() + 1)
		thingsList.push_back(things);
	else if (index < 1)
	{
		std::cout << "\n  1번보다 작은 번호를 입력하여 자동으로 1번으로 추가합니다\n\n";
		thingsList.insert((thingsList.begin()), things);
		system("pause");
	}
	else if (index > thingsList.size()+1)
	{
		std::cout << "\n 마지막보다 큰 번호를 입력하여 자동으로 마지막으로 추가합니다\n\n";
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
	std::cout << "\ta.물건 구매하기\t\tq.나가기\n";
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
		return true;
	}
}