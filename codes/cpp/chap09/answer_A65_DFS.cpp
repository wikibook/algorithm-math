// ###############################
// # 깊이 우선 탐색을 이용한 구현
// ###############################

#include <iostream>
#include <vector>
using namespace std;

int N, A[100009], dp[100009];
vector<int> G[100009];

void dfs(int pos) {
	// 재귀적으로 계산하기
	for (int i = 0; i < G[pos].size(); i++) {
		int to = G[pos][i]; // to는 직속 부하 직원의 번호
		dfs(to);
		dp[pos] += (dp[to] + 1);
	}
}

int main() {
	// 입력
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> A[i];
		G[A[i]].push_back(i); // '상사→부하' 방향으로 에지를 추가
	}

	// 깊이 우선 탐색
	dfs(1);

	// 공백으로 구분해서 출력
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << dp[i];
	}
	cout << endl;
	return 0;
}
