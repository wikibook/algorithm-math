#include <stdio.h>
 
const long long mod = 998244353;
long long A, B, C;
 
int main() {
	// 입력
	scanf("%lld%lld%lld", &A, &B, &C);
	
	// 계산
	long long D = A * (A + 1) / 2; D %= mod;
	long long E = B * (B + 1) / 2; E %= mod;
	long long F = C * (C + 1) / 2; F %= mod;
	
	// 답 출력
	// 여기에서 (D * E * F) % mod로 해도, 중간에 10^27를 다루어야 할 수 있으므로
	// long long 자료형이라도 오버플로가 발생할 수 있으므로 주의
	printf("%lld\n", (D * E % mod) * F % mod);
	return 0;
}