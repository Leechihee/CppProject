#include "account.h"
#include <iostream>

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
void Things::thingsDisplay() {
	std::cout << thingsType << '\t' << count << '\t' << amount << std::endl;
}

void Things::setAmount(int Amount) {
	amount = Amount;
}

void Things::operator+(const int& Count) {
	this->count += Count;
}

void Things::operator-(const int& Count) {
	this->count -= Count;
}

void Things::operator+=(const int& Count) {
	*this + Count;
}

void Things::operator-=(const int& Count) {
	*this - Count;
}