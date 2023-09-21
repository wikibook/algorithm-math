#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, A[409];
int dp[409][409];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= 2 * N; i++) cin >> A[i];

	// 배열 dp 초기화
	for (int i = 1; i <= 2 * N; i++) {
		for (int j = 1; j <= 2 * N; j++) dp[i][j] = 1000000000;
	}
	
	// 동적 계획 알고리즘(초기 상태)
	for (int i = 1; i <= 2 * N - 1; i++) {
		dp[i][i + 1] = abs(A[i] - A[i + 1]);
	}

	// 동적 계획 알고리즘(전이)
	for (int LEN = 2; LEN <= 2 * N - 1; LEN++) {
		for (int l = 1; l <= 2 * N - LEN; l++) {
			int r = l + LEN;

			// l번째와 r번째를 지우는 경우
			dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + abs(A[l] - A[r]));

			// 2개의 구간을 합성시키는 경우
			for (int m = l; m < r; m++) {
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
			}
		}
	}

	// 출력
	cout << dp[1][2 * N] << endl;
	return 0;
}
