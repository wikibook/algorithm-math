#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int M, A[59], B[59];
int dp[19][309];

// l 페이지와 r 페이지 사이에 몇 개의 연결고리가 있는가?
int tsunagari(int l, int r) {
	int cnt = 0;
	for (int i = 1; i <= M; i++) {
		if (l <= A[i] && B[i] <= r) cnt++;
	}
	return cnt;
}

int main() {
	// 입력
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];

	// 배열 dp 초기화
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= N; j++) dp[i][j] = -1000000;
	}

	// 동적 계획 알고리즘(받는 전환 형식)
	dp[0][0] = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			// k는 '이전 장이 어느 페이지에서 끝났는지'
			for (int k = 0; k <= j - 1; k++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + tsunagari(k + 1, j));
			}
		}
	}

	// 출력
	cout << dp[K][N] << endl;
	return 0;
}
