// 양의 정수 A와 B의 최대 공약수를 리턴하는 함수
// GCD는 Greatest Common Divisor(최대 공약수)의 약자
long long GCD(long long A, long long B) {
	long long Answer = 0;
	for (long long i = 1; i <= min(A, B); i++) {
		if (A % i == 0 && B % i == 0) Answer = i;
	}
	return Answer;
}