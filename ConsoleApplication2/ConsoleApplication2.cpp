#include "shop.h"
#include <conio.h>

int main()
{
	Shop s;
	std::string type; int count, amount, index;

	while (true)
	{
		s.title();
		std::cout << "\n\t\ta. 로그인\tq. 종료\n";
		switch (_getch())
		{
		case 'a':
		case 'A':
		{
			Account* cur = nullptr;
			int choice = s.tryLogin();
			if (choice == 1)
				cur = new Seller("Admin");
			else if(choice == 2)
				cur = new Customer("Customer");
			bool login = true;
			while (login)
			{
				s.title(); s.menu();
				switch (_getch())
				{
				case 'a':
				case 'A':
					if (dynamic_cast<Seller*>(cur) != nullptr)
					{
						Seller oper = *dynamic_cast<Seller*>(cur);
						s.displayThingsList(oper);
						switch (_getch())
						{
						case 'a':
						case 'A':
							s.title();
							std::cout << "\n\ta. 추가\t\tb. 수정\t\tq. 뒤로가기\n";
							switch (_getch())
							{
							case'a':
							case'A':
								if (s.listFull())
								{
									s.title();
									std::cout << "\n\t품목리스트가 가득 차있어 추가를 취소합니다.\n\t  ";
									system("pause");
									break;
								}
								s.title();
								std::cout << "\n\t품목 종류를 입력하세요. : \t";
								std::getline(std::cin, type);
								std::cout << "\n\t개수을 입력하세요. : \t\t";
								std::cin >> count;
								std::cout << "\n\t가격를 입력하세요. : \t\t";
								std::cin >> amount;
								std::cout << "\n\t품목순서를 입력하세요.(현재 목록개수 : " << s.listSize() << ") : ";
								(std::cin >> index).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								s.pushThingsToList(oper.inputListThings(type, count, amount),index);
								s.title();
								std::cout << "\n\t  품목리스트에 추가하였습니다.\n\n\t  ";
								system("pause");
								break;
							case'b':
							case'B':
								s.title();
								std::cout << "\n\t수정할 품목순서를 입력하세요.(현재 목록개수 : " << s.listSize() << ") : ";
								std::cin >> index;
								std::cout << "\n\t수정할 가격를 입력하세요. : \t\t";
								(std::cin >> amount).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								if (s.thingsModify(index, amount))
								{
									s.title();
									std::cout << "\n\t가격을 수정하였습니다.\n\n\t";
									system("pause");
								}
								else
								{
									s.title();
									std::cout << "\n\t오류로 인해 가격을 수정하지못하였습니다.\n\n\t";
									system("pause");
								}
							default:
								break;
							}
							break;
						case'b':
						case'B':
							s.title();
							std::cout << "\n\t삭제할 품목순서를 입력하세요.(현재 목록개수 : " << s.listSize() << ") : ";
							(std::cin >> index).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							if (s.popThingsToList(index))
							{
								s.title();
								std::cout << "\n\t성공적으로 제거하였습니다.\n\n\t";
								system("pause");
							}
							else
							{
								s.title();
								std::cout << "\n\t오류로 인해 제거를 하지못하였습니다.\n\n\t";
								system("pause");
							}
							break;
						case'q':
						case'Q':
							break;
						default:
							break;
						}
					}
					else
					{
						Customer cust = *dynamic_cast<Customer*>(cur);
						s.displayThingsList(cust);
						switch (_getch())
						{
						case'a':
						case'A':
							s.title();
							std::cout << "\n\t구매하실 품목번호를 입력하세요 : ";
							std::cin >> index;
							if (s.buyTheThings(index, cust.buyThings()))
							{
								std::cout << "\n\t성공적으로 구매하였습니다.\n\t";
								system("pause");
							}
							else
							{
								std::cout << "\n\t오류로 인해 구매 실패했습니다..\n\t";
								system("pause");
							}
						case'q':
						case'Q':

						default:
							break;
						}
					}
					break;
				case 'b':
				case 'B':
					s.title();
					cur->displayInfo();
					break;
				case 'q':
				case 'Q':
					login = false;
					break;
				default:
					break;
				}
			}
			delete cur;
			break;
		}
		case 'q':
		case 'Q':
			return 0;
		default:
			continue;
		}
	}

	return 0;
}
