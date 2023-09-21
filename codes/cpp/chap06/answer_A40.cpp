#include <iostream>
using namespace std;

int main() {
	// 입력
	int N, A[200009]; long long cnt[109], Answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 개수를 센다
	for (int i = 1; i <= 100; i++) cnt[i] = 0;
	for (int i = 1; i <= N; i++) cnt[A[i]] += 1;

	// 답을 구한다
	// nC3 = n * (n-1) * (n-2) / 6 을 사용한다
	for (int i = 1; i <= 100; i++) {
		Answer += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
	}
	cout << Answer << endl;
	return 0;
}
