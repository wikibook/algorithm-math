#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; char c[159][159];
MaximumFlow Z; // MaximumFlow 클래스는 9.8절 참조

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> c[i][j];
	}

	// 클래스를 구성한다
	Z.init(2 * N + 2);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (c[i][j] == '#') Z.add_edge(i, N + j, 1);
		}
	}
	for (int i = 1; i <= N; i++) {
		Z.add_edge(2 * N + 1, i, 1); // 's → 파란색'의 에지
		Z.add_edge(N + i, 2 * N + 2, 1); // '빨간색 → t'의 에지
	}
	// 답 출력
	cout << Z.max_flow(2 * N + 1, 2 * N + 2) << endl;
	return 0;
}
