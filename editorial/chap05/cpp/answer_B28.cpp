#include <iostream>
using namespace std;

const int mod = 1000000007;
int N, a[10000009];

int main() {
	// 입력
	cin >> N;

	// 피보나치 수열 계산
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i <= N; i++) {
		a[i] = (a[i - 1] + a[i - 2]) % mod;
	}

	// 출력
	cout << a[N] << endl;
	return 0;
}
