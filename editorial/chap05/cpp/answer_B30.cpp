#include <iostream>
using namespace std;

// a의 b제곱을 m으로 나눈 나머지를 반환하는 함수
// 변수 p는 a^1 → a^2 → a^4 → a^8 → a^16 → ･･･으로 변화
long long Power(long long a, long long b, long long m) {
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		int wari = (1 << i);
		if ((b / wari) % 2 == 1) {
			Answer = (Answer * p) % m; // 'a의 2i 제곱'이 곱해졌을 때
		}
		p = (p * p) % m;
	}
	return Answer;
}

// a ÷ b를 m으로 나눈 나머지를 반환하는 함수
long long Division(long long a, long long b, long long m) {
	return (a * Power(b, m - 2, m)) % m;
}

// nCr mod 1000000007을 반환하는 함수
long long ncr(int n, int r) {
	const long long M = 1000000007;

	// 순서 1: 분자 a를 구한다
	long long a = 1;
	for (int i = 1; i <= n; i++) a = (a * i) % M;

	// 순서 2: 분모 b를 구한다
	long long b = 1;
	for (int i = 1; i <= r; i++) b = (b * i) % M;
	for (int i = 1; i <= n - r; i++) b = (b * i) % M;

	// 순서 3: 답을 구한다
	return Division(a, b, M);
}

int main() {
	// 입력
	long long H, W;
	cin >> H >> W;

	// 출력
	cout << ncr(H + W - 2, W - 1) << endl;
	return 0;
}
