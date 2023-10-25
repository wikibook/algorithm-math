#include <stdio.h>

int main() {
	// 입력
	long long N, S, A[61];
	scanf("%lld%lld", &N, &S);
	long long i, j;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}
	
	// 모든 패턴 탐색: (1LL << N)은 2의 N제곱
	for (i = 0; i < (1LL << N); i++) {
		long long sum = 0;
		for (j = 1; j <= N; j++) {
			// (i & (1LL << (j-1))) != 0LL이라면
			// i의 2진법 표기에서 아래에서 j번째 카드가 1이라는 의미입니다.
			// (1LL << j)는 C에서 "2의 j제곱을 의미합니다.
			if ((i & (1LL << (j - 1))) != 0LL) {
				sum += A[j];
			}
		}
		if (sum == S) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
