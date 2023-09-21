#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009]; // 노드 x가 파란색일 경우, visited[x] = true

void dfs(int pos) { // pos는 현재 위치
	visited[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i];
		if (visited[nex] == false) dfs(nex);
	}
	return;
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
	for (int i = 1; i <= N; i++) visited[i] = false;
	dfs(1);

	// 답 출력
	string Answer = "The graph is connected.";
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = "The graph is not connected.";
	}
	cout << Answer << endl;
	return 0;
}
