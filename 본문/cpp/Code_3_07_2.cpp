#include <iostream>
using namespace std;

int N, dp[54];

int main() {
	// 입력
	cin >> N;

	// 동적계획법 → 답 출력
	for (int i = 0; i <= N; i++) {
		if (i <= 1) dp[i] = 1;
		else dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N] << endl;
	return 0;
}