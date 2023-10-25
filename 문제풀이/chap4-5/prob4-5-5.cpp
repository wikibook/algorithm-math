#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> G[100009];

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	
	// 답 구하기
	int Answer = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 0; j < G[i].size(); j++) {
			// G[i][j]는 정점 i에 인접한 정점 중 j번째 정점
			if (G[i][j] < i) cnt += 1;
		}
		// 자기자신보다 번호가 작은 인접한 정점이 1개 있다면, answer에 1을 추가
		if (cnt == 1) Answer += 1;
	}
	
	// 출력
	cout << Answer << endl;
	return 0;
}