int sum(int numArray[], int length) {
	if (length == 0) {	// 길이가 0 이면 0 리턴
		return 0;
	}
	// 배열의 마지막 수를 더하고 탐색 길이를 1 줄여 sum 재귀호출
	return sum(numArray, length - 1) + numArray[length - 1];
}