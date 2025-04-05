#include "shop.h"
#include <windows.h>

// Shop Private Method
void Shop::ListTop()
{
	system("cls");
	for (int i = 0;i < 60;i++)
		std::cout << '=';
	std::cout << "\n\t품목\t\t남은 개수\t\t가격\n";
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
        " ■■■■■  ",
        "■           ",
        "■           ",
        " ■■■■■  ",
        "          ■ ",
        "          ■ ",
        "■■■■■   "
    };
    std::string H[] = {
        "■        ■  ",
        "■        ■  ",
        "■        ■  ",
        "■■■■■■  ",
        "■        ■  ",
        "■        ■  ",
        "■        ■  "
    };
    std::string O[] = {
        " ■■■■■  ",
        "■        ■  ",
        "■        ■  ",
        "■        ■  ",
        "■        ■  ",
        "■        ■  ",
        " ■■■■■   "
    };
    std::string P[] = {
        " ■■■■■  ",
        "■       ■  ",
        "■       ■  ",
        "■■■■■   ",
        "■           ",
        "■           ",
        "■           "
    };

    // 각 문자를 출력
    for (int i = 0; i < 7; i++) {
        std::cout << S[i] << "  " << H[i] << "  " << O[i] << "  " << P[i] << std::endl;
    }
    std::cout << std::endl;
}

void Shop::menu()
{
    title();
	std::cout << "a. 판매 품목 리스트 출력\t";
	std::cout << "b. 계정 정보 출력\n";
	std::cout << "q. 로그아웃\n";
}

// Seller Option Method
void Shop::displayThingsList(Seller seller)
{
	ListTop();
	displayList();
	std::cout << std::endl;
	std::cout << "    a.품목 추가/수정\tb.품목 제거\tq.나가기\n";
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
	std::cout << "\ta.물건 구매하기\t\tq.나가기\n";
}