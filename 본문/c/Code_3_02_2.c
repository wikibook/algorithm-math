#include <stdio.h>

// GCD는 Greatest Common Divisor(최대 공약수)의 약자
long long GCD(long long A, long long B) {
	while (A >= 1 && B >= 1) {
		if (A < B) B = B % A; // A < B라면, 큰 수를 b로 변경합니다.
		else A = A % B; // A >= B라면 큰 수를 a로 변경합니다.
	}
	if (A >= 1) return A;
	return B;
}

int main() {
	long long A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", GCD(A, B));
	return 0;
}
