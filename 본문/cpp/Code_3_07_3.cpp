#include <iostream>
#include <algorithm>
using namespace std;

long long N, W, w[109], v[109];
long long dp[109][100009];

int main() {
	// 입력
	cin >> N >> W;
	for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

	// 배열 초기화
	dp[0][0] = 0;
	for (int i = 1; i <= W; i++) dp[0][i] = -(1LL << 60);

	// 동적계획법
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= W; j++) {
			// j < w[i]라면, 방법A를 선택
			if (j < w[i]) dp[i][j] = dp[i - 1][j];
			// j >= w[i]라면 방법A와 방법B 중에 큰 것으로 선택
			if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	// 답 출력
	long long Answer = 0;
	for (int i = 0; i <= W; i++) Answer = max(Answer, dp[N][i]);
	cout << Answer << endl;
	return 0;
}