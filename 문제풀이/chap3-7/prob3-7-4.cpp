#include <iostream>
#include <algorithm>
using namespace std;

int N, S, A[69];
bool dp[69][10009];

int main() {
	// 입력
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 배열 초기화
	dp[0][0] = true;
	for (int i = 1; i <= S; i++) dp[0][i] = false;
	
	// 동적계획법
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			// j < A[i]라면, 카드 i를 선택할 수 없음
			if (j < A[i]) dp[i][j] = dp[i-1][j];
			// j >= A[i]라면, 선택/선택하지 않음이라는 선택지가 있음
			if (j >= A[i]) {
				if (dp[i-1][j] == true || dp[i-1][j-A[i]] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}
	
	// 답 출력
	if (dp[N][S] == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}