#include <iostream>
using namespace std;

// 배열 dp에 대해: dp[x]=true일 때 승리 상태, dp[x]=false일 때 패배 상태
int N, K, A[109];
bool dp[100009];

int main() {
	// 입력
	cin >> N >> K;
	for (int i = 1; i <= K; i++) cin >> A[i];

	// 승자를 계산한다
	for (int i = 0; i <= N; i++) {
		dp[i] = false;
		for (int j = 1; j <= K; j++) {
			if (i >= A[j] && dp[i - A[j]] == false) {
				dp[i] = true; // 패배 상태로 전환할 수 있다면, 승리 상태
			}
		}
	}

	// 출력
	if (dp[N] == true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
