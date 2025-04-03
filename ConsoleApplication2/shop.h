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
	void title(); // 메인화면 출력 / 아직 시도안함
	void menu(); // 행동을 선택할 수 있는 메뉴 출력
	// Seller Class Option
	void displayThingsList(Seller seller); // 판매자권한으로 품목 리스트 화면출력, 함수 오버로딩
	bool pushThingsToList(const Things& things); // 품목리스트에 품목 추가
	// Customer Class Option
	void displayThingsList(Customer custom); // 구매자 권한으로 품목 리스트 화면출력, 함수 오버로딩
	// Constructor / Destructor
	Shop() {} // 생성자
	~Shop() {} // 파괴자
};

#endif // !SHOP_H_