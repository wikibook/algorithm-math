#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[200009], B[200009]; // N, M ≦ 200000이므로 배열의 크기를 200009 정도로 설정했습니다.
vector<int> G[200009];
int color[200009];

void dfs(int pos) {
	for (int i : G[pos]) { // 범위기반 for 반복문
		if (color[i] == 0) {
			// color[pos]=1일 때 2, color[pos]=2일 때 1
			color[i] = 3 - color[pos];
			dfs(i);
		}
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
	for (int i = 1; i <= N; i++) color[i] = 0;
	for (int i = 1; i <= N; i++) {
		if (color[i] == 0) {
			// 정점 i가 흰색인 경우(아직 방문하지 않은 연결 성분인 경우)
			color[i] = 1;
			dfs(i);
		}
	}
	
	// 이분 그래프인지 판정
	bool Answer = true;
	for (int i = 1; i <= M; i++) {
		if (color[A[i]] == color[B[i]]) Answer = false;
	}
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}