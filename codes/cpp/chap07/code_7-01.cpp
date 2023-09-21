// a 이상 b 이하의 정수를 무작위로 반환하는 함수
int RandInt(int a, int b) {
	return a + rand() % (b - a + 1);
}
