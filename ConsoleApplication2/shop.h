#ifndef SHOP_H_
#define SHOP_H_

#include "account.h"
#include <vector>

class Shop {
	std::vector<Things> thingsList;
	int max = 10;
	void ListTop();
	void displayList();
public:
	// CUI Display Method
	void title(); // ����ȭ�� ��� / ���� �õ�����
	void menu(); // �ൿ�� ������ �� �ִ� �޴� ���
	//a. �Ǹ� ǰ�� ����Ʈ ���, b. ���� ���� ��� q. �α׾ƿ�
	// Seller Class Option
	void displayThingsList(Seller seller); // �Ǹ��ڱ������� ǰ�� ����Ʈ ȭ�����, �Լ� �����ε�
	bool pushThingsToList(const Things& things); // ǰ�񸮽�Ʈ�� ǰ�� �߰�, �����ϸ� ture, �����ϸ� false
	bool pushThingsToList(const Things& things, const int& index); // ǰ�� ����Ʈ�� index��°�� ǰ�� �߰�, �����ϸ� ture, �����ϸ� false
	bool popThingsToList(const int& index); // ǰ�񸮽�Ʈ�� �ִ� index��° ǰ�� ����, �����ϸ� ture, �����ϸ� false
	// Customer Class Option
	void displayThingsList(Customer custom); // ������ �������� ǰ�� ����Ʈ ȭ�����, �Լ� �����ε�
	// Constructor / Destructor
	Shop() {} // ������
	~Shop() {} // �ı���
};

#endif // !SHOP_H_