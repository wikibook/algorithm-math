// ###########################
// # 배열 dp를 사용하지 않는 구현
// ###########################

#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009];
int LEN = 0, L[100009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 동적 계획 알고리즘
	for (int i = 1; i <= N; i++) {
		int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
		L[pos] = A[i];
		if (pos > LEN) LEN += 1;
	}

	// 답을 출력
	cout << LEN << endl;
	return 0;
}
