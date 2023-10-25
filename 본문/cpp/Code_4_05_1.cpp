#include <iostream>
#include <vector>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009]; // G[i]는 정점i와 인접한 정점 리스트

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // 정점 A[i]와 인접한 정점으로 B[i]를 추가
		G[B[i]].push_back(A[i]); // 정점 B[i]와 인접한 정점으로 A[i]를 추가
	}

	// 출력(G[i].size()는 정점 i에 인접한 정점 리스트의 크기이므로 "차수"입니다).
	for (int i = 1; i <= N; i++) {
		cout << i << ": {";
		for (int j = 0; j < G[i].size(); j++) {
			if (j >= 1) cout << ","; // 쉼표로 구분해서 출력
			cout << G[i][j]; // // G[i].get(j)는 정점i와 인접한 정점 중에서 j번째 정점
		}
		cout << "}" << endl;
	}
	return 0;
}