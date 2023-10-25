#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long A[500009], B[500009], C[500009];

// 그래프
bool used[500009];
long long dist[500009]; // 최단거리 길이
vector<pair<int, long long>> G[500009];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
 
// 다익스트라 알고리즘
void dijkstra() {
	// 배열 초기화 등
	for (int i = 1; i <= N; i++) dist[i] = (1LL << 60);
	for (int i = 1; i <= M; i++) used[i] = false;
	dist[1] = 0;
	Q.push(make_pair(0, 1));

	// 큐 변경
	while (!Q.empty()) {
		int pos = Q.top().second; Q.pop();
		if (used[pos] == true) continue;
		used[pos] = true;
		for (pair<int, int> i : G[pos]) {
			int to = i.first, cost = dist[pos] + i.second;
			if (pos == 0) cost = i.second; // 정점 0의 경우는 제외
			if (dist[to] > cost) {
				dist[to] = cost;
				Q.push(make_pair(dist[to], to));
			}
		}
	}
}
 
int main() {
	// 입력/그래프 엣지 추가
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].push_back(make_pair(B[i], C[i]));
		G[B[i]].push_back(make_pair(A[i], C[i]));
	}
	
	// 다익스트라 알고리즘
	dijkstra();
	
	// 답 출력
	if (dist[N] == (1LL << 60)) cout << "-1" << endl;
	else cout << dist[N] << endl;
	return 0;
}