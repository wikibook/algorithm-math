#include <iostream>
using namespace std;

int N, A[109];

int solve(int l, int r) {
	if (r - l == 1) return A[l];
	int m = (l + r) / 2; // 구간 [l, r)의 중앙을 기준으로 분할 정복
	int s1 = solve(l, m); // s1는 A[l]+...+A[m-1]의 합계
	int s2 = solve(m, r); // s2는 A[m]+...+A[r-1]의 합계
	return s1 + s2;
}

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 재귀함수 호출 → 답 출력
	int Answer = solve(1, N + 1);
	cout << Answer << endl;
	return 0;
}