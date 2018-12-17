#include "Price.h"
#include <cstdlib>
#define SIZE 8

//���������� �� �����
int cmp(const void *f, const void *l) {
	return ((Price*)f)->get_name() > ((Price*)l)->get_name();
}

//��������� ������
void read(Price *p) {
	for (unsigned i = 0; i < SIZE; ++i) {
		try {
			cout << "���\n�������\n���������\n";
			cin >> p[i];
		}
		catch (const Exception& exc) {
			cout << exc.what();
			--i;
		}
	}
	qsort(p, SIZE, sizeof(Price), cmp);
}

//�����
void printBy(Price *p, const string& name) {

	int i;
	bool flag = true;
	/*����� � �����, ���� ����� ����� � �����*/
	for (i = 0; i < SIZE; ++i) {
		if (p[i].get_name() == name) {
			cout << p[i] << '\n';
			flag = false;
		}
	}
	if (flag) cout << "�� �����";

}
int main() {
	setlocale(LC_ALL, "");
	Price p[SIZE];
	int a;
	for (;;) {
		cout << "\n1. �������\n2. �����\n3. �����\n";
		cin >> a;
		if (a == 1) {
			read(p);
		}
		else if (a == 2) {
			cout << "������� ��������\n";
			string name;
			cin >> name;
			printBy(p, name);
		}
		else {
			return 0;
		}
	}
	return 0;
}