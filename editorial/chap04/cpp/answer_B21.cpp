#include <iostream>
#include <algorithm>
using namespace std;
 
int N;
int dp[1009][1009];
string S;
 
int main() {
	// 입력
	cin >> N;
	cin >> S;
 
	// 동적 계획 알고리즘(초기 상태)
	for (int i = 0; i < N; i++) dp[i][i] = 1;
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == S[i + 1]) dp[i][i + 1] = 2;
		else dp[i][i + 1] = 1;
	}
 
	// 동적 계획 알고리즘(상태 전환)
	for (int LEN = 2; LEN <= N - 1; LEN++) {
		for (int l = 0; l < N - LEN; l++) {
			int r = l + LEN;
 
			if (S[l] == S[r]) {
				dp[l][r] = max({ dp[l][r - 1], dp[l + 1][r], dp[l + 1][r - 1] + 2 });
			}
			else {
				dp[l][r] = max({ dp[l][r - 1], dp[l + 1][r] });
			}
		}
	}
 
	// 답을 구한다
	cout << dp[0][N - 1] << endl;
	return 0;
}
