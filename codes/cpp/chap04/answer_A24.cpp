#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], dp[100009];
int LEN = 0, L[100009]; // LEN은 L의 길이(예: L[4]까지 쓰여 있는 경우 LEN=4)

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 동적 계획 알고리즘
	for (int i = 1; i <= N; i++) {
		int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
		dp[i] = pos;

		// 배열 L을 업데이트
		L[dp[i]] = A[i];
		if (dp[i] > LEN) LEN += 1;
	}

	// 답을 출력
	cout << LEN << endl;
	return 0;
}
