#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	// 입력
	int N, K;
	cin >> N >> K;

	// 사건B의 개수를 yeosagun(여사건) 변수로 세고 → 답 출력
	long long yeosagun = 0;
	for (int a = 1; a <= N; a++) {
		for (int b = max(1, a - (K - 1)); b <= min(N, a + (K - 1)); b++) {
			for (int c = max(1, a - (K - 1)); c <= min(N, a + (K - 1)); c++) {
				if (abs(b - c) <= K - 1) yeosagun += 1;
			}
		}
	}
	cout << (long long)N * N * N - yeosagun << endl;
	return 0;
}