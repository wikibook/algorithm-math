#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, A[19];
int M, X[109], Y[109], Z[109];
int dist[1033];
vector<int> G[1033];

// 노드 pos의 상태에서 'idx 번째 조작'을 수행했을 때의 노드 번호를 반환한다
int GetNext(int pos, int idx) {
	int State[19]; // State[i]는 램프 i의 상태

	// 2진법으로 고치는 방법은 1.4절을 참조
	for (int i = 1; i <= N; i++) {
		int wari = (1 << (i - 1));
		State[i] = (pos / wari) % 2;
	}
	State[X[idx]] = 1 - State[X[idx]]; // 램프 X[idx]를 반전
	State[Y[idx]] = 1 - State[Y[idx]]; // 램프 Y[idx]를 반전
	State[Z[idx]] = 1 - State[Z[idx]]; // 램프 Z[idx]를 반전

	// 10진법으로 변환하는 방법도 1.4절을 참조
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (State[i] == 1) ret += (1 << (i - 1));
	}
	return ret;
}

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int j = 1; j <= M; j++) cin >> X[j] >> Y[j] >> Z[j];

	// 그래프에 에지를 추가
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 1; j <= M; j++) {
			int NextState = GetNext(i, j);
			G[i].push_back(NextState);
		}
	}

	// 시작 지점, 목표 지점의 노드 번호를 구한다
	int Goal = (1 << N) - 1;  // (1<<N)은 '2의 N 제곱'
	int Start = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] == 1) Start += (1 << (i - 1));
	}

	// 배열 초기화／시작 시점을 큐에 넣는다
	queue<int> Q;
	for (int i = 0; i < (1 << N); i++) dist[i] = -1;
	dist[Start] = 0;
	Q.push(Start);

	// 너비 우선 탐색
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i = 0; i < G[pos].size(); i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q.push(nex);
			}
		}
	}

	// 답을 출력
	cout << dist[Goal] << endl;
	return 0;
}
