#include <iostream>
#include <string>
using namespace std;
 
int N, K;
int dp[32][300009];
 
int main() {
	// 입력
	cin >> N >> K;
 
	// 1 회 조작 후 값 구하기
	for (int i = 1; i <= N; i++) {
		string str = to_string(i);
		dp[0][i] = i;
		for (int j = 0; j < str.size(); j++) {
			dp[0][i] -= (int)(str[j] - '0');
		}
	}
 
	// 사전 계산
	for (int d = 1; d <= 29; d++) {
		for (int i = 1; i <= N; i++) dp[d][i] = dp[d - 1][dp[d - 1][i]];
	}
 
	// 답을 구한다
	for (int i = 1; i <= N; i++) {
		int CurrentNum = i; // 현재 정수
		for (int d = 29; d >= 0; d--) {
			if ((K / (1 << d)) % 2 != 0) CurrentNum = dp[d][CurrentNum];
		}
		cout << CurrentNum << endl;
	}
	return 0;
}
