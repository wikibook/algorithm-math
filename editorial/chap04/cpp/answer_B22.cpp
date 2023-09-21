#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], B[100009];
int dp[100009];

int main() {
	// 입력
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> A[i];
	for (int i = 3; i <= N; i++) cin >> B[i];

	// 배열 dp 초기화
	dp[1] = 0;
	for (int i = 2; i <= N; i++) dp[i] = 2000000000;

	// 동적 계획 알고리즘
	for (int i = 1; i <= N; i++) {
		if (i <= N - 1) dp[i + 1] = min(dp[i + 1], dp[i] + A[i + 1]); // i+1로 가는 경우
		if (i <= N - 2) dp[i + 2] = min(dp[i + 2], dp[i] + B[i + 2]); // i+2로 이동하는 경우
	}

	// 출력
	cout << dp[N] << endl;
	return 0;
}
