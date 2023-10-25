#include <stdio.h>

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
	scanf("%d%d", &X, &Y);
	
	// a, b가 음수가 되어버리는 경우
	if (2 * Y - X < 0 || 2 * X - Y < 0) {
		printf("0\n");
		return 0;
	}
	
	// a, b가 정수가 아닌 경우
	if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) {
		printf("0\n");
		return 0;
	}
	
	// 이항계수의 분자와 분모 구하기(과정1 / 과정2)
	long long bunja = 1, bunmo = 1;
	long long a = (2 * Y - X) / 3, b = (2 * X - Y) / 3;
	for (int i = 1; i <= a + b; i++) { bunja *= i; bunja %= mod; }
	for (int i = 1; i <= a; i++) { bunmo *= i; bunmo %= mod; }
	for (int i = 1; i <= b; i++) { bunmo *= i; bunmo %= mod; }
	
	// 답 구하기(과정3)
	printf("%lld\n", Division(bunja, bunmo, mod));
	return 0;
}