#include <stdio.h>

int main() {
	// 입력
	long long N;
	scanf("%lld", &N);

	// 지불 방법 시뮬레이션
	long long answer = 0;
	while (N >= 10000) {
		N -= 10000;
		answer += 1;
	}
	while (N >= 5000) {
		N -= 5000;
		answer += 1;
	}
	while (N >= 1) {
		N -= 1000;
		answer += 1;
	}
	
	// 답 출력
	printf("%lld\n", answer);
	return 0;
}
