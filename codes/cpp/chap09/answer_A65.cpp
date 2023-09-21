#include <iostream>
#include <vector>
using namespace std;

int N, A[100009], dp[100009];
vector<int> G[100009];

int main() {
	// 입력
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> A[i];
		G[A[i]].push_back(i); // '상사→부하' 방향으로 에지를 추가
	}
	// 동적 계획 알고리즘(dp[x]는 직원 x의 부하직원 수)
	for (int i = N; i >= 1; i--) {
		dp[i] = 0;
		for (int j = 0; j < G[i].size(); j++) dp[i] += (dp[G[i][j]] + 1);
	}
	// 공백으로 구분해서 출력
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << dp[i];
	}
	cout << endl;
	return 0;
}
