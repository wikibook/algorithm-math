#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A[109][19];
int dp[109][1024];

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}

	// 배열 초기화
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < (1 << N); j++) dp[i][j] = 1'000'000'000;
	}

	// 동적 계획 알고리즘
	dp[0][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < (1 << N); j++) {
			// already[k] = 1일 때, 물품 k는 이미 무료 상태다
			int already[19];
			for (int k = 1; k <= N; k++) {
				if ((j / (1 << (k - 1))) % 2 == 0) already[k] = 0;
				else already[k] = 1;
			}

			// 쿠폰 i를 선택한 경우의 정수 표현 v를 계산한다
			int v = 0;
			for (int k = 1; k <= N; k++) {
				if (already[k] == 1 || A[i][k] == 1) v += (1 << (k - 1));
			}

			// 이동을 수행한다
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			dp[i][v] = min(dp[i][v], dp[i - 1][j] + 1);
		}
	}

	// 출력(모두 선택한 경우의 정수 표현은 2^N-1)
	if (dp[M][(1 << N) - 1] == 1'000'000'000) cout << "-1" << endl;
	else cout << dp[M][(1 << N) - 1] << endl;
	return 0;
}
