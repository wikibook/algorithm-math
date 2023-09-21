#include <iostream>
using namespace std;

int N, Q, State = 1;
int E[200009];

int main() {
	// 입력 → 배열 준비
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) E[i] = i;

	// 쿼리 처리
	for (int i = 1; i <= Q; i++) {
		int Type, x, y; cin >> Type;

		// [1] 변경 조작
		if (Type == 1) {
			cin >> x >> y;
			if (State == 1) E[x] = y;
			if (State == 2) E[N + 1 - x] = y;
		}

		// [2] 반전 조작
		if (Type == 2) {
			if (State == 1) State = 2;
			else State = 1;
		}

		// [3] 취득 조작
		if (Type == 3) {
			cin >> x;
			if (State == 1) cout << E[x] << endl;
			if (State == 2) cout << E[N + 1 - x] << endl;
		}
	}
	return 0;
}
