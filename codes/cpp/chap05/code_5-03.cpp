// 정수 A와 B의 최대 공약수를 반환하는 함수
// GCD는 최대 공약수(Greatest Common Divisor)의 약자
int GCD(int A, int B) {
	int ret = 0;
	for (int x = 1; x <= min(A, B); x++) {
		if (A % x == 0 && B % x == 0) ret = x;
	}
	return ret;
}
