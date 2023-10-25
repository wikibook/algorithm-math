#include <stdio.h>

long long GCD(long long A, long long B) {
	while (A >= 1 && B >= 1) {
		if (A < B) B = B % A; // A < B라면, 큰 수를 b로 변경합니다.
		else A = A % B; // A >= B라면 큰 수를 a로 변경합니다.
	}
	if (A >= 1) return A;
	return B;
}

long long N;
long long A[100009];

int main() {
	// 입력
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	
	// 답 구하기
	long long R = GCD(A[1], A[2]);
	for (int i = 3; i <= N; i++) {
		R = GCD(R, A[i]);
	}
	
	// 출력
	printf("%lld\n", R);
	return 0;
}