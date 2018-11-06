#include<iostream>
#include<string>
#include "Membership.h"
#include "Shared.h"
#include "Customer.h"
#include "Master.h"

using namespace std;

int main(){
	int menu_index;
	int member_index;
	Menu menu[4];
	fopen_Menu(*menu,menu_index); //need debug
	Material meterial=fopen_Material();
	Purchase purchase=fopen_Purchase();
	Membership member[1];
	fopen_Membership(*member,member_index);//need debug

	while (true) {
		int i;
		string in;
		cout << "�ݰ����ϴ�. SolChan Cafe�Դϴ�." << endl << "���ϴ� ���񽺸� ����ּ���!" << endl;
		cout << "1. �ֹ�" << endl << "2.������ ���" << endl << "3. ���α׷� ����" << endl << ">>";
		cin >> i;

		switch (i) {
		case 1:
			start_customer(*menu,menu_index,meterial,purchase,*member,member_index);
			break;
		case 2:
			start_master(); //*menu, menu_index, meterial, purchase, *member, member_index
			break;
		case 3:
			cout << "���α׷��� �����մϴ�.";
			in = "quit";
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
		
		if (in == "quit")
			break;
	}

	fclose_Menu(); //Menu,meterial fwrite
	fclose_Material();
	fclose_Purchase();
	fclose_Membership();

}