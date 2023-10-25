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

int main() {
	const long long MOD = 1000000007;
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", modpow(a, b, MOD));
	return 0;
}
