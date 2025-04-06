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
	void title(); // 메인화면 출력
	void menu(); // 행동을 선택할 수 있는 메뉴 출력
	//a. 판매 품목 리스트 출력, b. 계정 정보 출력 q. 로그아웃
	int tryLogin(void); // a을 누르면 1을 리턴하여 관리자권한 출력, b를 누르면 2를 리턴하여 구매자권한 출력, b를 누르면 3을 리턴하여 나가기 출력
	int listSize(void); // 품목 리스트 사이즈 출력
	bool listFull(void); // 품목 리스트이 가득찼는지 확인
	// Seller Class Option
	void displayThingsList(Seller seller); // 판매자권한으로 품목 리스트 화면출력, 함수 오버로딩
	bool pushThingsToList(const Things& things,int index = 1); // 품목 리스트에 index번째에 품목 추가, 성공하면 ture, 실패하면 false
	bool popThingsToList(const int& index = 1); // 품목리스트에 있는 index번째 품목 제거, 성공하면 ture, 실패하면 false
	bool thingsModify(const int& index, const int& amount);
	// Customer Class Option
	void displayThingsList(Customer custom); // 구매자 권한으로 품목 리스트 화면출력, 함수 오버로딩
	bool buyTheThings(const int& index, const int& count); // 구매자 권한으로 품목 사기. 개수가 남는다면 true, 0개이하가 된다면 false 리턴
	// Constructor / Destructor
	Shop() {} // 생성자
	~Shop() {} // 파괴자
};

#endif