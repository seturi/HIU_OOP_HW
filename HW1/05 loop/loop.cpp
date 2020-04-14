#include <iostream>
using namespace std;

int main(void) {
	cout << "반복 횟수를 입력하세요. : ";
	int n;	// 반복 횟수를 입력받아 저장할 변수 선언
	cin >> n;
	cout << endl;
	
	// a. for
	cout << "a. for" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Hello world" << endl;
	}

	// b. while
	cout << "b. while" << endl;
	int i = 0;
	while (i < n) {
		cout << "Hello world" << endl;
		i++;
	}
	
	// c. do while
	cout << "c. do while" << endl;
	i = 0;
	do {
		cout << "Hello world" << endl;
		i++;
	} while (i < n);
	
	return 0;
}