#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <iostream>

class Things; // Seller class���� Things�� ���� ���� �̸� ����, Ŭ���� ������ �Ʒ�

class Account { //�߻�ȭ Ŭ����
protected: // ������ ������ protected�� �ܺηκ��� ��ȣ / �ڳ� Ŭ������ ���
	std::string name;
	bool permission = false;
public:
	Account(std::string Name) : name(Name) {}
	virtual void displayInfo() = 0; // ���� ���� ���, ���������Լ�
	// std::cout << "�̸� : " << name << "\nID : " << id << std::endl << "���� : ===\n";
	virtual bool activite(); // ���� ���� ��� / �Ǹ��ڱ����̸� true, �Һ��ڱ����̸� false ���
	~Account() {}
};

class Seller : public Account {
public:
	Seller(std::string Name) : Account(Name) { permission = true; }
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
	void thingsDisplay(void); // �� ��ü�� � ǰ���� �Ǹ��ϰ� ���� ���� ������ ������ ȭ�鿡 ���
	void setAmount(int Amount); // ǰ�� ���� �缳��
	void operator+(const int& Count); // ǰ���� ������ �߰��� �� �� + ������
	void operator+=(const int& Count); // ǰ���� ������ �߰��� �� �� += ������
	bool operator-(const int& Count); // ǰ���� ������ ������ �� �� - ������, �������� ��, ���� ������ 0�̸� false ����, �ƴ϶�� true ����
	bool operator-=(const int& Count); // ǰ���� ������ ������ �� �� -= ������, �������� ��, ���� ������ 0�̸� false ����, �ƴ϶�� true ����
};
#endif