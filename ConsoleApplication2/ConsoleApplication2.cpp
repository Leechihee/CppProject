#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

class Things; // Seller class에서 Things를 쓰기 위해 미리 선언, 클래스 구현은 아래

class Account { //추상화 클래스
protected: // 계정의 정보를 protected로 외부로부터 보호 / 자녀 클래스로 상속
	std::string name, id, password;
	bool permission = false;
public:
	Account(std::string Name, std::string Id, std::string Password) : id(Id), name(Name), password(Password) {}
	virtual void displayInfo() = 0; // 계정 정보 출력, 순수가상함수
	// std::cout << "이름 : " << name << "\nID : " << id << std::endl << "권한 : ===\n";
	virtual bool activite(); // 계정 권한 출력 / 판매자권한이면 true, 소비자권한이면 false 출력
	bool login(std::string ID, std::string PW); // ID와 PW가 둘 다 맞지 않으면 false, 맞다면 true
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
	using Account::Account; // 생성자 상속
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
	void thingsDisplay(void); // 이 객체가 어떤 품목을 판매하고 현재 남은 개수와 가격을 화면에 출력
	void setAmount(int Amount); // 품목 가격 재설정
	void operator+(const int& Count); // 품목의 개수를 추가할 때 쓸 + 연산자
	void operator+=(const int& Count); // 품목의 개수를 추가할 때 쓸 += 연산자
	bool operator-(const int& Count); // 품목의 개수를 제거할 때 쓸 - 연산자, 연산했을 때, 남은 개수가 0이면 false 리턴, 아니라면 true 리턴
	bool operator-=(const int& Count); // 품목의 개수를 제거할 때 쓸 -= 연산자, 연산했을 때, 남은 개수가 0이면 false 리턴, 아니라면 true 리턴
};

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
	bool pushThingsToList(const Things& things, const int& index = 1); // 품목 리스트에 index번째에 품목 추가, 성공하면 ture, 실패하면 false
	bool popThingsToList(const int& index = 1); // 품목리스트에 있는 index번째 품목 제거, 성공하면 ture, 실패하면 false
	// Customer Class Option
	void displayThingsList(Customer custom); // 구매자 권한으로 품목 리스트 화면출력, 함수 오버로딩
	// Constructor / Destructor
	Shop() {} // 생성자
	~Shop() {} // 파괴자
};

int main()
{
	Seller seller("Admin", "admin", "00000000");
	Customer customer("Customer", "customer", "99999999");

	Shop test;
	test.displayThingsList(seller);

	return 0;
}

// Account Public Method
bool Account::login(std::string ID, std::string PW)
{
	return (id == ID && password == PW);
}

bool Account::activite()
{
	return permission;
}

// Seller Public Method
void Seller::displayInfo() {
	std::cout << "이름 : " << name << "\nID : " << id << std::endl << "권한 : 관리자\n";
}

Things Seller::inputListThings(std::string Type, int Count, int Amount) {
	return Things(Type, Count, Amount);
}

// Customer Public Method
void Customer::displayInfo() {
	std::cout << "이름 : " << name << "\nID : " << id << std::endl << "권한 : 소비자\n";
}

int Customer::buyThings() {
	int count;
	std::cout << "구매할 수량을 입력하세요 : ";
	std::cin >> count;
	return count;
}

// Things Public Method
Things::Things(const Things& things)
{
	this->thingsType = things.thingsType;
	this->count = things.count;
	this->amount = things.amount;
}

void Things::thingsDisplay() {
	std::cout << '\t' << thingsType << "\t\t   " << count << "\t\t\t" << amount << '\t' << std::endl;
}

void Things::setAmount(int Amount) {
	amount = Amount;
}

void Things::operator+(const int& Count) {
	this->count += Count;
}

bool Things::operator-(const int& Count) {
	if (this->count > Count)
	{
		this->count -= Count;
		return true;
	}
	else
	{
		std::cout << "구매 총량이 현재 수량보다 많게 입력되어 현재수량만큼 구매했습니다.\n";
		this->count = 0;
		return false;
	}
}

void Things::operator+=(const int& Count) {
	*this + Count;
}

bool Things::operator-=(const int& Count) {
	return *this - Count;
}

#include "shop.h"
#include <windows.h>

// Shop Private Method
void Shop::ListTop()
{
	system("cls");
	for (int i = 0;i < 60;i++)
		std::cout << '=';
	std::cout << "\n\t품목\t\t남은 개수\t\t가격\n";
}

void Shop::displayList()
{
	int index;
	for (index = 0;index < thingsList.size();index++)
	{
		std::cout << index + 1 << ". ";
		thingsList[index].thingsDisplay();
	}
	for (;index < max;index++)
	{
		std::cout << index + 1 << ". ";
		std::cout << '\t' << "----" << "\t\t  " << "----" << "\t\t\t" << "----" << '\t' << std::endl;
	}
	for (int i = 0;i < 60;i++)
		std::cout << '=';
	std::cout << std::endl;
}

// Shop Public Method
void Shop::title()
{
	return;
}

void Shop::menu()
{
	std::cout << "a. 판매 품목 리스트 출력\t";
	std::cout << "b. 계정 정보 출력\n";
	std::cout << "q. 로그아웃\n";
}

// Seller Option Method
void Shop::displayThingsList(Seller seller)
{
	ListTop();
	displayList();
	std::cout << std::endl;
	std::cout << "    a.품목 추가/수정\tb.품목 제거\tq.나가기\n";
}

bool Shop::pushThingsToList(const Things& things, const int& index)
{
	if (thingsList.empty())
		thingsList.push_back(things);
	else if (index < 1 || index > thingsList.size() || thingsList.size() >= max)
		return false;
	else
		thingsList.insert((thingsList.begin() + index - 1), things);
	return true;
}

bool Shop::popThingsToList(const int& index)
{
	if (index < 1 || index>thingsList.size())
		return false;
	thingsList.erase(thingsList.begin() + index - 1);
	return true;
}

// Customer Option Method
void Shop::displayThingsList(Customer customer)
{
	ListTop();
	displayList();
	std::cout << std::endl;
	std::cout << "\ta.물건 구매하기\t\tq.나가기\n";
}