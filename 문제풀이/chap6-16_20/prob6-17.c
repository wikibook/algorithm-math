#include <stdio.h>

int main() {
	// 입력
	long long N;
	scanf("%lld", &N);

	// 세로 길이를 1부터 √N까지 전체 탐색
	long long answer = (1LL << 60);
	long long x;
	for (x = 1; x * x <= N; x++) {
		if (N % x == 0 && answer > 2 * x + 2 * (N / x)) {
			answer = 2 * x + 2 * (N / x);
		}
	}

	// 답 출력
	printf("%lld\n", answer);

	return 0;
}