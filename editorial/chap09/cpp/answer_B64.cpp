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
 
	// 답의 복원(Place는 현재 위치: 골대에서 출발)
	vector<int> Answer;
	int Place = N;
	while (true) {
		Answer.push_back(Place);
		if (Place == 1) break;
 
		// Place 앞의 정점으로는 어디가 좋을까?
		for (int i = 0; i < G[Place].size(); i++) {
			int nex = G[Place][i].first;
			int cost = G[Place][i].second;
			if (cur[nex] + cost == cur[Place]) {
				Place = nex;
				break;
			}
		}
	}
	reverse(Answer.begin(), Answer.end());
 
	// 출력
	for (int i = 0; i < Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
