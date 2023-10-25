#include <iostream>
using namespace std;

long long N, S, A[61];

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 모든 패턴 탐색: (1LL<<N)은 2의 N제곱
	for (long long i = 0; i < (1LL << N); i++) {
		long long sum = 0;
		for (int j = 1; j <= N; j++) {
			// (i & (1LL << (j-1))) != 0LL이라면, i의 2진법 표시 아래에서 j번째 자리가 1
			// (1LL << (j-1))는 C++에서 "2의 j-1제곱을 의미합니다.
			if ((i & (1LL << (j-1))) != 0LL) sum += A[j];
		}
		if (sum == S) { cout << "Yes" << endl; return 0; }
	}
	cout << "No" << endl;
	return 0;
}
