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
	std::cout << "�̸� : " << name << "\nID : " << id << std::endl << "���� : ������\n";
}

Things Seller::inputListThings(std::string Type, int Count, int Amount) {
	return Things(Type, Count, Amount);
}

// Customer Public Method
void Customer::displayInfo() {
	std::cout << "�̸� : " << name << "\nID : " << id << std::endl << "���� : �Һ���\n";
}

int Customer::buyThings() {
	int count;
	std::cout << "������ ������ �Է��ϼ��� : ";
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
		std::cout << "���� �ѷ��� ���� �������� ���� �ԷµǾ� ���������ŭ �����߽��ϴ�.\n";
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