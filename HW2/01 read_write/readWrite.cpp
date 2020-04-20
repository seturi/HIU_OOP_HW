#define LENGTH 1024		// 배열의 길이를 지정한 상수 선언
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	// 초기 파일 열기
	ifstream file ("hello.txt");
	if (!file) {	// 파일 열기 실패 시 종료
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	// 복사 파일 열기
	ofstream cpyfile("copyHello.txt");
	if (!cpyfile) {	// 파일 열기 실패 시 종료
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	char data[LENGTH];	// 파일 데이터를 저장할 배열 선언
	
	while (!file.eof())		// 파일의 끝까지 읽기
	{
		file.read(data, LENGTH);			// 파일 데이터를 읽어 배열에 저장
		int bytes = file.gcount();		// 실제로 읽은 데이터의 바이트 수 저장할 변수 선언
		cpyfile.write(data, bytes);	// 배열에 저장한 데이터를 파일에 복사
	}
	cout << "복사 완료" << endl;

	// 파일 닫기
	file.close();
	cpyfile.close();
	
	return 0;
}