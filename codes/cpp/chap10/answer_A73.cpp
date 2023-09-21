#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 입력/그래프를 나타내는 변수
int N, M, A[100009], B[100009], C[100009], D[100009];
vector<pair<int, int>> G[8009];

// 데이크스트라 알고리즘에서 사용하는 변수
long long cur[8009]; bool kakutei[8009];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		if (D[i] == 1) {
			G[A[i]].push_back(make_pair(B[i], 10000 * C[i] - 1));
			G[B[i]].push_back(make_pair(A[i], 10000 * C[i] - 1));
		}
		else {
			G[A[i]].push_back(make_pair(B[i], 10000 * C[i]));
			G[B[i]].push_back(make_pair(A[i], 10000 * C[i]));
		}
	}

	// 배열 초기화
	for (int i = 1; i <= N; i++) kakutei[i] = false;
	for (int i = 1; i <= N; i++) cur[i] = (1LL << 60);

	// 시작 지점을 큐에 추가
	cur[1] = 0;
	Q.push(make_pair(cur[1], 1));

	// 데이크스트라 알고리즘
	while (!Q.empty()) {
		// 다음에 확정할 노드를 구한다
		int pos = Q.top().second; Q.pop();
		if (kakutei[pos] == true) continue;

		// cur[nex]의 값을 업데이트한다
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
	// 마라톤 코스의 거리: cur[N]/10000을 소수점 이하를 자른 값
	// 코드상 나무의 수: cur[N]과 Distance*10000의 차이
	long long Distance = (cur[N] + 9999) / 10000;
	long long NumTrees = Distance * 10000 - cur[N];
	cout << Distance << " " << NumTrees << endl;
	return 0;
}
