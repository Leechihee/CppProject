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
	void title(); // ����ȭ�� ���
	void menu(); // �ൿ�� ������ �� �ִ� �޴� ���
	//a. �Ǹ� ǰ�� ����Ʈ ���, b. ���� ���� ��� q. �α׾ƿ�
	int tryLogin(void); // a�� ������ 1�� �����Ͽ� �����ڱ��� ���, b�� ������ 2�� �����Ͽ� �����ڱ��� ���, b�� ������ 3�� �����Ͽ� ������ ���
	int listSize(void); // ǰ�� ����Ʈ ������ ���
	bool listFull(void); // ǰ�� ����Ʈ�� ����á���� Ȯ��
	// Seller Class Option
	void displayThingsList(Seller seller); // �Ǹ��ڱ������� ǰ�� ����Ʈ ȭ�����, �Լ� �����ε�
	bool pushThingsToList(const Things& things,int index = 1); // ǰ�� ����Ʈ�� index��°�� ǰ�� �߰�, �����ϸ� ture, �����ϸ� false
	bool popThingsToList(const int& index = 1); // ǰ�񸮽�Ʈ�� �ִ� index��° ǰ�� ����, �����ϸ� ture, �����ϸ� false
	bool thingsModify(const int& index, const int& amount);
	// Customer Class Option
	void displayThingsList(Customer custom); // ������ �������� ǰ�� ����Ʈ ȭ�����, �Լ� �����ε�
	bool buyTheThings(const int& index, const int& count); // ������ �������� ǰ�� ���. ������ ���´ٸ� true, 0�����ϰ� �ȴٸ� false ����
	// Constructor / Destructor
	Shop() {} // ������
	~Shop() {} // �ı���
};

#endif