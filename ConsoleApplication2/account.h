#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <iostream>

class Things; // Seller class에서 Things를 쓰기 위해 미리 선언, 클래스 구현은 아래

class Account { //추상화 클래스
protected: // 계정의 정보를 protected로 외부로부터 보호 / 자녀 클래스로 상속
	std::string name, id, password;
	bool permission = false;
public:
	Account(std::string Name, std::string Id, std::string Password) : id(Id), name(Name), password(Password){}
	virtual void displayInfo() = 0; // 계정 정보 출력, 순수가상함수
	virtual bool activite(); // 계정 권한 출력 / 판매자권한이면 true, 소비자권한이면 false 출력
	bool login(std::string ID, std::string PW);
	~Account() {}
};

class Seller : public Account {
public:
	Seller(std::string Name, std::string Id, std::string Password) : Account(Name, Id, Password) { permission = true; }
	void displayInfo() override;
	Things inputListThings(std::string Type, int Count, int Amount); // 판매할 물품 종류, 개수, 가격을 입력받아 Things 객체를 출력
};

class Customer : public Account {
public:
	using Account::Account; // 생성사 상속
	void displayInfo() override;
	int buyThings(void); // 구매할 품목의 개수를 입력받아 정수값으로 리턴
};

class Things {
	std::string thingsType; // 품목 종류
	int count; // 품목의 현재 개수
	int amount; // 품목의 현재 가격
public:
	Things(std::string Type, int Count, int Amount) : thingsType(Type), count(Count), amount(Amount) {}
	Things(const Things& things);
	void thingsDisplay(); // 이 객체가 어떤 품목을 판매하고 현재 남은 개수와 가격을 화면에 출력
	void setAmount(int Amount); // 품목 가격 재설정
	void operator+(const int& Count); // 품목의 개수를 추가할 때 쓸 + 연산자
	void operator+=(const int& Count); // 품목의 개수를 추가할 때 쓸 += 연산자
	void operator-(const int& Count); // 품목의 개수를 제거할 때 쓸 - 연산자
	void operator-=(const int& Count); // 품목의 개수를 제거할 때 쓸 -= 연산자
};
#endif