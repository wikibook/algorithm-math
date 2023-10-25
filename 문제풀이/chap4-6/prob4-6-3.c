#include <stdio.h>
 
const long long mod = 1000000007;
long long N;
 
long long modpow(long long a, long long b, long long m) {
	// 반복제곱법(p에는 a^1, a^2, a^4, a^8, ...가 할당됨)
	long long p = a, Answer = 1;
	for (int i = 0; i < 60; i++) {
		if ((b & (1LL << i)) != 0) { Answer *= p; Answer %= m; }
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
	scanf("%d", &N);
	
	// 답 계산
	long long V = modpow(4, N + 1, mod) - 1;
	long long Answer = Division(V, 3, mod);
	
	// 출력
	printf("%lld\n", Answer);
	return 0;
}