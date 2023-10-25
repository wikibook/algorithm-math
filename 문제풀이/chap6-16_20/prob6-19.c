#include <stdio.h>

int N, B[109];

int main() {
	// 입력
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N - 1; i++) {
		scanf("%d", &B[i]);
	}

	// 수열A의 요소 합계 구하기
	int answer = B[1] + B[N - 1];
	for (i = 2; i <= N - 1; i++) {
		answer += (B[i - 1] < B[i] ? B[i - 1] : B[i]);
	}

	// 답 출력
	printf("%d\n", answer);

	return 0;
}