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

const long long MOD = 1000000007;
long long fact[200009];

long long ncr(int n, int r) {
	// ncr은 n!를 r! × (n-r)!으로 나눈 값
	return division(fact[n], fact[r] * fact[n - r] % MOD, MOD);
}

int main() {
	// 배열 초기화(fact[i]는 i의 거듭제곱을 1000000007로 나눈 나머지)
	fact[0] = 1;
	int i;
	for (i = 1; i <= 200000; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	// 입력 → 답 출력
	int X, Y;
	scanf("%d%d", &X, &Y);
	printf("%lld\n", ncr(X + Y, Y));
	
	return 0;
}
