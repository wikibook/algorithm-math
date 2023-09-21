#include <iostream>
#include <algorithm>
using namespace std;

int N, K, A[1009], B[1009], C[1009], D[1009];
int P[1000009], Q[1000009];

int main() {
	// 입력
	cin >> N >> K;
	for (int x = 1; x <= N; x++) cin >> A[x];
	for (int y = 1; y <= N; y++) cin >> B[y];
	for (int z = 1; z <= N; z++) cin >> C[z];
	for (int w = 1; w <= N; w++) cin >> D[w];

	// 배열 P를 작성
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) P[(x - 1) * N + y] = A[x] + B[y];
	}

	// 배열 Q를 작성
	for (int z = 1; z <= N; z++) {
		for (int w = 1; w <= N; w++) Q[(z - 1) * N + w] = C[z] + D[w];
	}
	// 배열 Q를 오름차순으로 정렬
	sort(Q + 1, Q + (N * N) + 1);

	// 바이너리 서치
	for (int i = 1; i <= N * N; i++) {
		int pos1 = lower_bound(Q + 1, Q + (N * N) + 1, K - P[i]) - Q;
		if (pos1 <= N * N && Q[pos1] == K - P[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	// 발견하지 못한 경우
	cout << "No" << endl;
	return 0;
}
