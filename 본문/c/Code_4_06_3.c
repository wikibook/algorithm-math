#include <stdio.h>

int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	const long long MOD = 1000000007;
	long long answer = 1; // a의 0 제곱은 1이므로, Answer=1로 초기화해둡니다.
	long long i;
	for (i = 1; i <= b; i++) {
		answer = (answer * a) % MOD;
	}
	printf("%lld\n", answer);
	return 0;
}
