int sum(int numArray[], int length) {
	int result = 0;		// 결과값을 저장할 변수 선언
	
	for (int i = 0; i < length; i++) {	// 배열을 돌며 정수를 더함
		result += numArray[i];
	}

	return result;	// 변수에 저장된 결과값 반환
}