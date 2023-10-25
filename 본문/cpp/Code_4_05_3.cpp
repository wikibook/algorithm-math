#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A[100009], B[100009];
int dist[100009];
vector<int> G[100009];

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 너비 우선 탐색 초기화(dist[i] = -1일 때, 미도달 흰색 정점으로 판단)
	for (int i = 1; i <= N; i++) dist[i] = -1;
	queue<int> Q; // 큐 Q 정의하기
	Q.push(1); dist[1] = 0; // Q에 1을 추가(조작1)

	// 너비 우선 탐색
	while (!Q.empty()) {
		int pos = Q.front(); // Q의 앞부분 확인(조작2)
		Q.pop(); // Q의 앞부분 추출(조작3)
		for (int i = 0; i < (int)G[pos].size(); i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q.push(nex); // Q에 nex를 추가(조작1)
			}
		}
	}

	// 정점1에서 각 정점까지의 최단 거리를 출력
	for (int i = 1; i <= N; i++) cout << dist[i] << endl;
	return 0;
}