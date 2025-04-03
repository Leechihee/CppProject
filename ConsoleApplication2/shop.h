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
	//a. 판매 품목 리스트 출력, b. 계정 정보 출력 q. 로그아웃
	// Seller Class Option
	void displayThingsList(Seller seller); // 판매자권한으로 품목 리스트 화면출력, 함수 오버로딩
	bool pushThingsToList(const Things& things); // 품목리스트에 품목 추가, 성공하면 ture, 실패하면 false
	bool pushThingsToList(const Things& things, const int& index); // 품목 리스트에 index번째에 품목 추가, 성공하면 ture, 실패하면 false
	bool popThingsToList(const int& index); // 품목리스트에 있는 index번째 품목 제거, 성공하면 ture, 실패하면 false
	// Customer Class Option
	void displayThingsList(Customer custom); // 구매자 권한으로 품목 리스트 화면출력, 함수 오버로딩
	// Constructor / Destructor
	Shop() {} // 생성자
	~Shop() {} // 파괴자
};

#endif // !SHOP_H_