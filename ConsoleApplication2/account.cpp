#include "account.h"
#include <limits>
#include <windows.h>

// Seller Public Method
void Seller::displayInfo() {
	std::cout << "\n\t\t      이름 : " << name << std::endl << "\n\t\t      권한 : 관리자\n\n\t    ";
	system("pause");
}

Things Seller::inputListThings(std::string Type, int Count, int Amount) {
	return Things(Type, Count, Amount);
}

// Customer Public Method
void Customer::displayInfo() {
	std::cout << "\n\t\t      이름 : " << name << std::endl << "\n\t\t      권한 : 소비자\n\n\t    ";
	system("pause");
}

int Customer::buyThings() {
	int count;
	std::cout << "\n\t구매할 수량을 입력하세요 : ";
	(std::cin >> count).ignore(2, '\n');;
	return count;
}

// Things Public Method
Things::Things(const Things& things)
{
	this->thingsType = things.thingsType;
	this->count = things.count;
	this->amount = things.amount;
}

void Things::thingsDisplay() {
	std::cout << '\t' << thingsType << "\t\t   " << count << "\t\t\t" << amount << '\t' << std::endl;
}

void Things::setAmount(int Amount) {
	amount = Amount;
}

void Things::operator+(const int& Count) {
	this->count += Count;
}

bool Things::operator-(const int& Count) {
	if (this->count > Count)
	{
		this->count -= Count;
		return true;
	}
	else
	{
		std::cout << "\n구매 총량이 현재 수량보다 많게 입력되어 현재수량만큼 구매했습니다.\n";
		this->count = 0;
		return false;
	}
}

void Things::operator+=(const int& Count) {
	*this + Count;
}

bool Things::operator-=(const int& Count) {
	return *this - Count;
}