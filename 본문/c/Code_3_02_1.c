#include <stdio.h>

// 양의 정수 A와 B의 최대 공약수를 리턴하는 함수
// GCD는 Greatest Common Divisor(최대 공약수)의 약자
long long GCD(long long A, long long B) {
	long long answer = 0;
	long long i;
	for (i = 1; i <= A && i <= B; i++) {
		if (A % i == 0 && B % i == 0) {
			answer = i;
		}
	}
	return answer;
}

int main() {
	long long A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", GCD(A, B));
	return 0;
}
