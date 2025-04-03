#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <iostream>

class Things; // Seller class���� Things�� ���� ���� �̸� ����

class Account {
protected: // ������ ������ protected�� �ܺηκ��� ��ȣ / �ڳ� Ŭ������ ���
	std::string name, id, password;
public:
	Account(std::string Name, std::string Id, std::string Password) : id(Id), name(Name) {}
	virtual void displayInfo() = 0; // ���� ���� ���
	virtual bool login(std::string ID, std::string PW) = 0;
	~Account() {}
};

class Seller : public Account {
public:
	using Account::Account;
	void displayInfo() override;
	Things inputListThings(std::string Type, int Count, int Amount); // �Ǹ��� ��ǰ ����, ����, ������ �Է¹޾� Things ��ü�� ���
};

class Customer : public Account {
public:
	using Account::Account;
	void displayInfo() override;
	int buyThings(void); // ������ ǰ���� ������ �Է¹޾� ���������� ����
};

class Things {
	std::string thingsType; // ǰ�� ����
	int count; // ���� ����
	int amount; // ���� ����
public:
	Things(std::string Type, int Count, int Amount) : thingsType(Type), count(Count), amount(Amount) {}
	void thingsDisplay(); // �� ��ü�� � ǰ���� �Ǹ��ϰ� ���� ���� ������ ������ ȭ�鿡 ���
	void setAmount(int Amount); // ǰ�� ���� �缳��
	void operator+(const int& Count); // ǰ���� ������ �߰��� �� �� + ������
	void operator+=(const int& Count); // ǰ���� ������ �߰��� �� �� += ������
	void operator-(const int& Count); // ǰ���� ������ ������ �� �� - ������
	void operator-=(const int& Count); // ǰ���� ������ ������ �� �� -= ������
};
#endif