#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> G[100009]; // 인접 리스트

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // '노드 A[i]에 인접한 노드'로 B[i]를 추가
		G[B[i]].push_back(A[i]); // '노드 B[i]에 인접한 노드'로 A[i]를 추가
	}

	// 출력
	for (int i = 1; i <= N; i++) {
		cout << i << ": {";
		for (int j = 0; j < G[i].size(); j++) {
			if (j >= 1) cout << ", ";
			cout << G[i][j];
		}
		cout << "}" << endl;
	}
	return 0;
}
