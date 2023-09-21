#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 입력/그래프
int N, M, A[100009], B[100009], C[100009];
vector<pair<int, int>> G[100009];

// 데이크스트라 알고리즘
int cur[100009]; bool kakutei[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].push_back(make_pair(B[i], C[i]));
		G[B[i]].push_back(make_pair(A[i], C[i]));
	}

	// 배열 초기화
	for (int i = 1; i <= N; i++) kakutei[i] = false;
	for (int i = 1; i <= N; i++) cur[i] = 2000000000;

	// 시작 지점을 큐에 추가
	cur[1] = 0;
	Q.push(make_pair(cur[1], 1));

	// 데이크스트라 알고리즘
	while (!Q.empty()) {
		// 다음에 확정할 노드를 구한다
		int pos = Q.top().second; Q.pop();

		// Q의 최소 요소가 '이미 확정한 노드'인 경우
		if (kakutei[pos] == true) continue;

		// cur[x] 값을 업데이트한다
		kakutei[pos] = true;
		for (int i = 0; i < G[pos].size(); i++) {
			int nex = G[pos][i].first;
			int cost = G[pos][i].second;
			if (cur[nex] > cur[pos] + cost) {
				cur[nex] = cur[pos] + cost;
				Q.push(make_pair(cur[nex], nex));
			}
		}
	}

	// 답을 출력
	for (int i = 1; i <= N; i++) {
		if (cur[i] == 2000000000) cout << "-1" << endl;
		else cout << cur[i] << endl;
	}
	return 0;
}
