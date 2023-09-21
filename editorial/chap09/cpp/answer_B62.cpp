#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// 입력
int N, M, A[100009], B[100009];
 
// 깊이 우선 탐색
vector<int> G[100009];
bool visited[100009];
 
// 깊이 우선 탐색의 흔적
vector<int> Path, Answer;
 
void dfs(int pos) {
	// 결승점에 도착한 경우
	if (pos == N) {
		Answer = Path;
		return;
	}
 
	// 그 외의 경우
	visited[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i];
		if (visited[nex] == false) {
			Path.push_back(nex); // 경로에 정점 nex 추가
			dfs(nex);
			Path.pop_back(); // 경로에서 정점 nex 제거
		}
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
	Path.push_back(1); // 경로에 정점 1(시작점) 추가
	dfs(1);
 
	// 답 출력
	for (int i = 0; i < Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
