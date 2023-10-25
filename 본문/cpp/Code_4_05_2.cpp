#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009]; // visited[pos]=false일 때 정점x가 흰색, true일 때 회색

void dfs(int pos) {
	visited[pos] = true;
	// for (int i : G[pos])을 "범위기반 for 반복문"이라고 부릅니다.
	for (int i : G[pos]) {
		if (visited[i] == false) dfs(i);
	}
}

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 깊이 우선 탐색
	dfs(1);

	// 연결되어 있는지 판정(Answer=true라면 연결됨)
	bool Answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = false;
	}
	if (Answer == true) cout << "The graph is connected." << endl;
	else cout << "The graph is not connected." << endl;
	return 0;
}
