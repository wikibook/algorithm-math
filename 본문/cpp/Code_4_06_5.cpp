#include <iostream>
using namespace std;

const long long mod = 1000000007;
int X, Y;

long long modpow(long long a, long long b, long long m) {
	// 반복제곱법(p에는 a^1, a^2, a^4, a^8, ...가 할당됨)
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}

// division(a, b, m)은 a÷b mod m를 리턴하는 함수
long long Division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int main() {
	// 입력
	cin >> X >> Y;

	// 이항계수의 분자와 분모 구하기(과정1 / 과정2)
	long long bunza = 1, bunmo = 1;
	for (int i = 1; i <= X + Y; i++) { bunza *= i; bunza %= mod; }
	for (int i = 1; i <= X; i++) { bunmo *= i; bunmo %= mod; }
	for (int i = 1; i <= Y; i++) { bunmo *= i; bunmo %= mod; }

	// 답 구하기(과정3)
	cout << Division(bunza, bunmo, mod) << endl;
	return 0;
}