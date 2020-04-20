#define LENGTH 1024		// �迭�� ���̸� ������ ��� ����
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	// �ʱ� ���� ����
	ifstream file ("hello.txt");
	if (!file) {	// ���� ���� ���� �� ����
		cout << "���� ���� ����" << endl;
		return 0;
	}

	// ���� ���� ����
	ofstream cpyfile("copyHello.txt");
	if (!cpyfile) {	// ���� ���� ���� �� ����
		cout << "���� ���� ����" << endl;
		return 0;
	}

	char data[LENGTH];	// ���� �����͸� ������ �迭 ����
	
	while (!file.eof())		// ������ ������ �б�
	{
		file.read(data, LENGTH);			// ���� �����͸� �о� �迭�� ����
		int bytes = file.gcount();		// ������ ���� �������� ����Ʈ �� ������ ���� ����
		cpyfile.write(data, bytes);	// �迭�� ������ �����͸� ���Ͽ� ����
	}
	cout << "���� �Ϸ�" << endl;

	// ���� �ݱ�
	file.close();
	cpyfile.close();
	
	return 0;
}