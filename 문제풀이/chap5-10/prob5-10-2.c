#include <stdio.h>
 
const long long mod = 1000000007;
long long N;
 
int main() {
	// 입력
	scanf("%lld", &N);
	
	// 답 구하기
	long long val = N * (N + 1) / 2;
	val %= mod;
	printf("%lld\n", val * val % mod);
	return 0;
}