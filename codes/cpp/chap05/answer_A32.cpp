#include <iostream>
using namespace std;

// 배열 dp에 대해: dp[x]=true일 때 승리 상태, dp[x]=false일 때 패배 상태
int N, A, B;
bool dp[100009];

int main() {
	// 입력
	cin >> N >> A >> B;

	// 승자를 계산한다
	for (int i = 0; i <= N; i++) {
		if (i >= A && dp[i - A] == false) dp[i] = true; // 승리 상태
		else if (i >= B && dp[i - B] == false) dp[i] = true; // 승리 상태
		else dp[i] = false; // 패배 상태
	}

	// 출력
	if (dp[N] == true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
