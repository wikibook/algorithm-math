#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// 입력되는 변수・답변
int N, T, A[100009], B[100009];
int Answer[100009];
 
// 그래프・깊이 우선 탐색
vector<int> G[100009];
bool visited[100009];
 
// 깊이 우선 탐색를 수행하는 기능（pos는 현재 위치）
// 반환 값은 직원 pos의 등급입니다.
int dfs(int pos) {
	// 먼저 직원 pos의 등급을 0으로 설정한다.
	visited[pos] = true;
	Answer[pos] = 0;
 
	// 탐색하기
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i];
		if (visited[nex] == false) {
			int ret = dfs(nex);
			Answer[pos] = max(Answer[pos], ret + 1); // 등급 갱신하기
		}
	}
 
	// 값 반환
	return Answer[pos];
}
 
int main() {
	// 입력
	cin >> N >> T;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // A[i]→B[i]의 방향으로 에지를 추가
		G[B[i]].push_back(A[i]); // B[i]→A[i]의 방향으로 에지를 추가
	}
 
	// 깊이 우선 탐색
	dfs(T);
 
	// 출력
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
