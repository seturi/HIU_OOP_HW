int sum(int numArray[], int length) {
	int result = 0;		// ������� ������ ���� ����
	
	for (int i = 0; i < length; i++) {	// �迭�� ���� ������ ����
		result += numArray[i];
	}

	return result;	// ������ ����� ����� ��ȯ
}