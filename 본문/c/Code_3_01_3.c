#include <stdio.h>

int main() {
	long long N;
	scanf("%lld", &N);
	long long i;
	for (i = 1; i * i <= N; i++) {
		if (N % i != 0) continue;
		printf("%lld\n", i); // i를 약수로 추가
		if (i != N / i) {
			printf("%lld\n", N / i); // i ≠ N/i라면, N/i도 약수에 추가
		}
	}
	return 0;
}
