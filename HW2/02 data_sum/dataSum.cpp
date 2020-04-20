#include <iostream>
#include <fstream>
using namespace std;

void fdataSum(string fileName) {		// 파일 명을 매개변수로 받는 함수 선언

	// 읽어 올 파일 열기
	ifstream data(fileName);

	if (!data) {						// 파일 열기 실패 시 종료
		cout << "파일 열기 실패" << endl;
	} else {							// 파일 열기 성공 시 실행
		while (true) {
			int num1, num2;				// 파일의 정수 데이터를 저장할 변수 두 개 선언
			data >> num1 >> num2;		// 파일에서 각 줄의 두 정수 데이터를 순서대로 두 변수에 저장

			if (data.fail()) break;		// 오류 발생 시 종료

			cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;	// 두 정수를 더한 값을 출력
		}
	}
}

int main() {
	fdataSum("Text.txt");				// 함수 호출
	
	return 0;
}