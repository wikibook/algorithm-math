#include <bits/stdc++.h>
using namespace std;
 
int K, dist[1 << 18];
bool used[1 << 18];
vector<pair<int, int>> G[1 << 18];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
 
// 다익스트라 알고리즘
void dijkstra() {
	// 배열 초기화 등
	for (int i = 0; i < K; i++) dist[i] = (1 << 30);
	for (int i = 0; i < K; i++) used[i] = false;
	Q.push(make_pair(0, 0)); // 여기에서 dist[0] = 0로는 되지 않으므로 주의

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
	// 입력
	cin >> K;
	
	// 그래프 엣지 추가
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 && j == 0) continue;
			G[i].push_back(make_pair((i * 10 + j) % K, j));
		}
	}
	
	// 다익스트라 알고리즘/출력
	dijkstra();
	cout << dist[0] << endl;
	return 0;
}