#include <stdio.h>

int N, A[109];
int Answer = 0;

int main() {
	// 입력
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	// 답 계산
	for (int i = 1; i <= N; i++) {
		Answer += A[i];
	}

	// 출력
	printf("%d\n", Answer % 100);
	return 0;
}
