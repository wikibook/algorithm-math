#include <stdio.h>

long long modpow(long long a, long long b, long long m) {
	// 반복제곱법(p에는 a^1, a^2, a^4, a^8, ...가 할당됨)
	long long p = a, answer = 1;
	int i;
	for (i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) {
			answer = (answer * p) % m;
		}
		p = (p * p) % m;
	}
	return answer;
}

// division(a, b, m)은 a÷b mod m를 리턴하는 함수
long long division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int main() {
	// 입력
	int X, Y;
	scanf("%d%d", &X, &Y);
	
	// 이항계수의 분자와 분모 구하기(과정1 / 과정2)
	const long long MOD = 1000000007;
	long long bunja = 1, bunmo = 1;
	int i;
	for (i = 1; i <= X + Y; i++) {
		bunja = (bunja * i) % MOD;
	}
	for (i = 1; i <= X; i++) {
		bunmo = (bunmo * i) % MOD;
	}
	for (i = 1; i <= Y; i++) {
		bunmo = (bunmo * i) % MOD;
	}
	
	// 답 구하기(과정3)
	printf("%lld\n", division(bunja, bunmo, MOD));
	
	return 0;
}
