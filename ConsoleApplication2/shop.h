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
	// Seller Class Option
	void displayThingsList(Seller seller); // �Ǹ��ڱ������� ǰ�� ����Ʈ ȭ�����, �Լ� �����ε�
	bool pushThingsToList(const Things& things); // ǰ�񸮽�Ʈ�� ǰ�� �߰�
	// Customer Class Option
	void displayThingsList(Customer custom); // ������ �������� ǰ�� ����Ʈ ȭ�����, �Լ� �����ε�
	// Constructor / Destructor
	Shop() {} // ������
	~Shop() {} // �ı���
};

#endif // !SHOP_H_