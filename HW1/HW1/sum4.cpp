int sum(int numArray[], int length) {
	if (length == 0) {	// ���̰� 0 �̸� 0 ����
		return 0;
	}
	// �迭�� ������ ���� ���ϰ� Ž�� ���̸� 1 �ٿ� sum ���ȣ��
	return sum(numArray, length - 1) + numArray[length - 1];
}