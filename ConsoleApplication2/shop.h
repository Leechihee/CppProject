#ifndef SHOP_H_
#define SHOP_H_

#include "./account.h"
#include <vector>


Seller seller("Leechihee", "20220938", "0011223344");
Customer customer("Leechihee", "20220938", "0011223344");

class Shop {
	std::vector<Things> thingsList;
	bool state = false;
public:
	// CUI Display Method
	void title(); // ����ȭ�� ���
	// Shop State Method
	bool tryLogin(std::string ID, std::string PW); // ID, PW�� �Է��Ͽ� �α��νõ�
	// Seller Class Option
	void menu(Seller* seller); // �Ǹ��ڱ������� �޴� ���, �Լ� �����ε�
	void displayThingsList(Seller* seller); // �Ǹ��ڱ������� ǰ�� ����Ʈ ȭ�����, �Լ� �����ε�
	bool pushThingsToList(const Things& things); // ǰ�񸮽�Ʈ�� ǰ�� �߰�
	// Customer Class Option
	void menu(Customer* custom); // �����ڱ������� �޴� ���, �Լ� �����ε�
	void displayThingsList(Customer* custom); // ������ �������� ǰ�� ����Ʈ ȭ�����, �Լ� �����ε�
	// Constructor / Destructor
	Shop() {} // ������
	~Shop() {} // �ı���
};

#endif // !SHOP_H_