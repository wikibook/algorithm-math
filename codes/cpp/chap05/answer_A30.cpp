#include <iostream>
using namespace std;

// a ÷ b를 m으로 나눈 나머지를 반환하는 함수
// 함수 Power는 5.4절을 참조
long long Division(long long a, long long b, long long m) {
	return (a * Power(b, m - 2, m)) % m;
}

int main() {
	// 입력
	const long long M = 1000000007;
	long long n, r;
	cin >> n >> r;

	// 순서 1: 분자 a를 구한다
	long long a = 1;
	for (int i = 1; i <= n; i++) a = (a * i) % M;

	// 순서 2: 분모 b를 구한다
	long long b = 1;
	for (int i = 1; i <= r; i++) b = (b * i) % M;
	for (int i = 1; i <= n - r; i++) b = (b * i) % M;

	// 순서 3: 답을 구한다
	cout << Division(a, b, M) << endl;
	return 0;
}
