#include "Customer.h"

using namespace std;

Cart::Cart() {}
void Cart::add_cart(string s, int n) {}
void Cart::print_cart() {}
int Cart::payment_cart() {}

void start_customer(Menu& menu, int menu_index, Material& material, Purchase& purchase, Membership& member, int member_index) {
	
	Cart c;

	while (true) {
		for (int i = 0; i < menu_index; ++i) {//
			if (menu.check_metreial == 1) {
				cout << endl;
			}
			else if (menu.check_metreial == 0) {
				cout << "(�ֹ� �Ұ�)" << endl;
			}
		}

		string s_order;
		cout << "�ֹ� �Ͻ� �޴��� �Է����ּ���.(��ȣ)" << endl << ">>";
		cin >> s_order;

		int i_order;
		cout << "������ �Է����ּ���." << endl << ">>";
		cin >> i_order;
		c.add_cart(s_order, i_order);

		cout << "�ֹ� ����" << endl;
		c.print_cart();

		int i_pay;
		cout << "������ 0��, �߰� �ֹ��� 1���� �Է����ּ���." << endl << ">>";
		cin >> i_pay;
		
		if (i_pay == 1)
			break;
	}

	int pay = c.payment_cart();

	char c_member;
	cout << "ȸ���̽Ű���? (Y/N)" << endl << ">>";
	cin >> c_member;


	if (c_member == 'Y') {
		cout << "���̵� �Է����ּ���." << endl << ">>";
		string str_member;
		int customer_index=-1;
		getline(cin, str_member);

		for (int i = 0; i < member_index; ++i) {
			if (member.get_name == str_member) {
				customer_index = i;
				cout << "����Ʈ �ܾ��� " << member.get_point << "�Դϴ�." << endl;
				break;
			}
		}

		if (customer_index != -1) {
			char c_point;
			cout << "����Ʈ�� ����Ͻðڽ��ϱ�? (Y/N)" << endl << ">>";
			cin >> c_point;
			if (c_point == 'Y') {
				purchase.set_revenue(pay - member.get_point());
				cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
			}
			else {
				member.set_point(pay);
				purchase.set_revenue(pay);
				cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
			}
		}
		else {
			cout << "�߸��� �����Դϴ�." << endl;
		}
	}
	else if (c_member == 'N') {
		char c_join;
		cout << "ȸ�������� �Ͻðڽ��ϱ�? (Y/N)" << endl << ">>";
		cin >> c_join;

		if (c_join == 'Y') {
			string id;
			int flag;
			while (true) {
				cout << "����� ���̵� �Է����ּ���" << endl << ">>";
				getline(cin, id);
				for (flag=0; flag < member_index; ++flag) {//
					if (member.get_name == id) {
						cout << "�ߺ� ���̵��Դϴ�." << endl;
						break;
					}
				}
				if (flag == member_index)
					break;
			}
			create_Membership(id);
			member.set_point(pay);//
			purchase.set_revenue(pay);
			cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
		}
		else {
			purchase.set_revenue(pay);
			cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
		}
	}

}