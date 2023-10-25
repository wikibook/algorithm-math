#include <stdio.h>

int N, dp[54];

int main() {
	// 입력
	scanf("%d", &N);

	// 동적계획법 → 답 출력
	int i;
	for (i = 0; i <= N; i++) {
		if (i <= 1) dp[i] = 1;
		else dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%d\n", dp[N]);
	return 0;
}
