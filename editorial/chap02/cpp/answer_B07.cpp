#include <iostream>
using namespace std;

int N, T;
int L[500009], R[500009];
int Answer[500009], B[500009];

int main() {
	// 입력
	cin >> T >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 전일 비에 더한다
	for (int i = 0; i <= T; i++) B[i] = 0;
	for (int i = 1; i <= N; i++) {
		B[L[i]] += 1;
		B[R[i]] -= 1;
	}

	// 누적 합을 구한다
	Answer[0] = B[0];
	for (int d = 1; d <= T; d++) Answer[d] = Answer[d - 1] + B[d];

	// 출력
	for (int d = 0; d < T; d++) cout << Answer[d] << endl;
	return 0;
}
