#include <stdio.h>

int N; long long W, w[109], v[109];
long long dp[109][100009];

int main() {
	// 입력
	scanf("%d%lld", &N, &W);
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf("%lld%lld", &w[i], &v[i]);
	}

	// 배열 초기화
	dp[0][0] = 0;
	for (i = 1; i <= W; i++) {
		dp[0][i] = -(1LL << 60);
	}

	// 동적계획법
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= W; j++) {
			// j < w[i-1]라면, 방법A로 선택
			if (j < w[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			// j >= w[i-1]라면 방법A와 방법B 중에 큰 것으로 선택
			if (j >= w[i]) {
				long long v1 = dp[i - 1][j];
				long long v2 = dp[i - 1][j - w[i]] + v[i];
				dp[i][j] = (v1 > v2 ? v1 : v2); // v1과 v2 중에서 큰 값
			}
		}
	}

	// 답을 계산하고 출력
	long long answer = 0;
	for (i = 0; i <= W; i++) {
		answer = (answer > dp[N][i] ? answer : dp[N][i]);
	}
	printf("%lld\n", answer);
	return 0;
}
