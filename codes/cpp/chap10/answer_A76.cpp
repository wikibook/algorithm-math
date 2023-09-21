#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;
long long N, W, L, R, X[150009];
int dp[150009], sum[150009];

int main() {
	// 입력
	cin >> N >> W >> L >> R;
	for (int i = 1; i <= N; i++) cin >> X[i];

	// 서쪽 끝을 징검다리 0, 동쪽 끝을 징검다리 N+1로 간주한다
	X[0] = 0; X[N + 1] = W;

	// 동적 계획 알고리즘・출력
	dp[0] = 1; sum[0] = 1;
	for (int i = 1; i <= N + 1; i++) {
		int posL = lower_bound(X, X + N + 2, X[i] - R) - X;
		int posR = lower_bound(X, X + N + 2, X[i] - L + 1) - X; posR--;

		// dp[i]의 값을 누적 합으로 계산(뺄셈 한 뒤 나머지를 구하는 것에 주의!)
		if (posR == -1) dp[i] = 0;
		else dp[i] = sum[posR];
		if (posL >= 1) dp[i] -= sum[posL - 1];
		dp[i] = (dp[i] + mod) % mod;

		// 누적 합 sum[i]를 업데이트
		sum[i] = sum[i - 1] + dp[i];
		sum[i] %= mod;
	}
	cout << dp[N + 1] << endl;
	return 0;
}
