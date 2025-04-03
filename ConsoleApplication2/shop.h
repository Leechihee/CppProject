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
	void title(); // 메인화면 출력
	// Shop State Method
	bool tryLogin(std::string ID, std::string PW); // ID, PW를 입력하여 로그인시도
	// Seller Class Option
	void menu(Seller* seller); // 판매자권한으로 메뉴 출력, 함수 오버로딩
	void displayThingsList(Seller* seller); // 판매자권한으로 품목 리스트 화면출력, 함수 오버로딩
	bool pushThingsToList(const Things& things); // 품목리스트에 품목 추가
	// Customer Class Option
	void menu(Customer* custom); // 구매자권한으로 메뉴 출력, 함수 오버로딩
	void displayThingsList(Customer* custom); // 구매자 권한으로 품목 리스트 화면출력, 함수 오버로딩
	// Constructor / Destructor
	Shop() {} // 생성자
	~Shop() {} // 파괴자
};

#endif // !SHOP_H_