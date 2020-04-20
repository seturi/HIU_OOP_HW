#include <iostream>
#include <fstream>
using namespace std;

void fdataSum(string fileName) {		// ���� ���� �Ű������� �޴� �Լ� ����

	// �о� �� ���� ����
	ifstream data(fileName);

	if (!data) {						// ���� ���� ���� �� ����
		cout << "���� ���� ����" << endl;
	} else {							// ���� ���� ���� �� ����
		while (true) {
			int num1, num2;				// ������ ���� �����͸� ������ ���� �� �� ����
			data >> num1 >> num2;		// ���Ͽ��� �� ���� �� ���� �����͸� ������� �� ������ ����

			if (data.fail()) break;		// ���� �߻� �� ����

			cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;	// �� ������ ���� ���� ���
		}
	}
}

int main() {
	fdataSum("Text.txt");				// �Լ� ȣ��
	
	return 0;
}