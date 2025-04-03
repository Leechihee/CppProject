#include "account.h"

// Account Public Method
bool Account::login(std::string ID, std::string PW)
{
	return (id == ID && password == PW);
}

bool Account::activite()
{
	return permission;
}

// Seller Public Method
void Seller::displayInfo() {
	std::cout << "이름 : " << name << "\nID : " << id << std::endl << "권한 : 관리자\n";
}

Things Seller::inputListThings(std::string Type, int Count, int Amount) {
	return Things(Type, Count, Amount);
}

// Customer Public Method
void Customer::displayInfo() {
	std::cout << "이름 : " << name << "\nID : " << id << std::endl << "권한 : 소비자\n";
}

int Customer::buyThings() {
	int count;
	std::cout << "구매할 수량을 입력하세요 : ";
	std::cin >> count;
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
		std::cout << "구매 총량이 현재 수량보다 많게 입력되어 현재수량만큼 구매했습니다.\n";
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