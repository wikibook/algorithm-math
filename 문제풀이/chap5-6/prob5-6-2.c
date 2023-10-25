#include <stdio.h>

const long long mod = 1000000007;
long long N;
long long A[300009];
long long power[300009];

int main() {
	// 입력
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	
	// 2^i 구하기
	power[0] = 1;
	for (int i = 1; i <= N; i++) {
		power[i] = (2 * power[i - 1]) % mod;
	}
	
	// 답 구하기
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer += power[i - 1] * A[i];
		Answer %= mod;
	}
	
	// 출력
	printf("%lld\n", Answer);
	return 0;
}