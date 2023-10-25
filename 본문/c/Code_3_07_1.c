#include <stdio.h>
#include <stdlib.h>

int N, H[100009], dp[100009];

int main() {
	// 입력
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &H[i]);
	}

	// 동적계획법 → 답 출력
	for (i = 1; i <= N; i++) {
		if (i == 1) dp[i] = 0;
		if (i == 2) dp[i] = abs(H[i - 1] - H[i]);
		if (i >= 3) {
			int v1 = dp[i - 1] + abs(H[i - 1] - H[i]); // 1개 이전 발판에서 점프할 때
			int v2 = dp[i - 2] + abs(H[i - 2] - H[i]); // 2개 이전 발판에서 점프할 때
			dp[i] = (v1 < v2 ? v1 : v2); // v1과 v2 중에서 작은 값
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}
