#include <iostream>
#include <cmath>
using namespace std;

int N, X[159], Y[159];
int P[159]; // 도시를 방문하는 순서 정보
bool visited[159]; // visited[i]=true일 때 도시 i를 방문했음

// 도시 p와 q 사이의 거리를 구하는 함수
double GetDistance(int p, int q) {
	return sqrt((X[p] - X[q]) * (X[p] - X[q]) + (Y[p] - Y[q]) * (Y[p] - Y[q]));
}

// 탐욕 알고리즘을 사용해 답을 구하는 함수
void PlayGreedy() {
	// 배열 초기화
	int CurrentPlace = 1;
	for (int i = 1; i <= N; i++) visited[i] = false;
	P[1] = 1; visited[1] = true;

	// 탐욕 알고리즘 시작
	for (int i = 2; i <= N; i++) {
		double MinDist = 10000.0; // 현 시점에서의 거리의 최소
		int Min_ID = -1; // 다음은 어떤 도시로 이동해야 좋은가

		// 거리가 최소가 되는 도시를 찾는다
		for (int j = 1; j <= N; j++) {
			if (visited[j] == true) continue;
			double NewDist = GetDistance(CurrentPlace, j);
			if (MinDist > NewDist) {
				MinDist = NewDist;
				Min_ID = j;
			}
		}

		// 현재 위치 업데이트
		visited[Min_ID] = true;
		P[i] = Min_ID;
		CurrentPlace = Min_ID;
	}

	// 최후에 방문하는 도시
	P[N + 1] = 1;
}

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 탐욕 알고리즘
	PlayGreedy();

	// 출력
	for (int i = 1; i <= N + 1; i++) cout << P[i] << endl;
	return 0;
}
