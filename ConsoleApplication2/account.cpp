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