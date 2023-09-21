#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], P[100009], Q[100009];
int D, L[100009], R[100009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> D;
	for (int d = 1; d <= D; d++) cin >> L[d] >> R[d];

	// P[i]를 구한다
	P[1] = A[1];
	for (int i = 2; i <= N; i++) P[i] = max(P[i - 1], A[i]);

	// Q[i]를 구한다
	Q[N] = A[N];
	for (int i = N - 1; i >= 1; i--) Q[i] = max(Q[i + 1], A[i]);

	// 각 날짜에 대해 답을 구한다
	for (int d = 1; d <= D; d++) {
		cout << max(P[L[d] - 1], Q[R[d] + 1]) << endl;
	}
	return 0;
}
