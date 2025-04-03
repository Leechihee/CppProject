#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <iostream>

class Things; // Seller class���� Things�� ���� ���� �̸� ����, Ŭ���� ������ �Ʒ�

class Account { //�߻�ȭ Ŭ����
protected: // ������ ������ protected�� �ܺηκ��� ��ȣ / �ڳ� Ŭ������ ���
	std::string name, id, password;
	bool permission = false;
public:
	Account(std::string Name, std::string Id, std::string Password) : id(Id), name(Name), password(Password){}
	virtual void displayInfo() = 0; // ���� ���� ���, ���������Լ�
	virtual bool activite(); // ���� ���� ��� / �Ǹ��ڱ����̸� true, �Һ��ڱ����̸� false ���
	bool login(std::string ID, std::string PW);
	~Account() {}
};

class Seller : public Account {
public:
	Seller(std::string Name, std::string Id, std::string Password) : Account(Name, Id, Password) { permission = true; }
	void displayInfo() override;
	Things inputListThings(std::string Type, int Count, int Amount); // �Ǹ��� ��ǰ ����, ����, ������ �Է¹޾� Things ��ü�� ���
};

class Customer : public Account {
public:
	using Account::Account; // ������ ���
	void displayInfo() override;
	int buyThings(void); // ������ ǰ���� ������ �Է¹޾� ���������� ����
};

class Things {
	std::string thingsType; // ǰ�� ����
	int count; // ǰ���� ���� ����
	int amount; // ǰ���� ���� ����
public:
	Things(std::string Type, int Count, int Amount) : thingsType(Type), count(Count), amount(Amount) {}
	Things(const Things& things);
	void thingsDisplay(); // �� ��ü�� � ǰ���� �Ǹ��ϰ� ���� ���� ������ ������ ȭ�鿡 ���
	void setAmount(int Amount); // ǰ�� ���� �缳��
	void operator+(const int& Count); // ǰ���� ������ �߰��� �� �� + ������
	void operator+=(const int& Count); // ǰ���� ������ �߰��� �� �� += ������
	void operator-(const int& Count); // ǰ���� ������ ������ �� �� - ������
	void operator-=(const int& Count); // ǰ���� ������ ������ �� �� -= ������
};
#endif