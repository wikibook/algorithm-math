#include <stdio.h>
 
int main() {
	// 입력
	long long N;
	scanf("%lld", &N);
	
	// 출력
	printf("%lld\n", N * (N - 1) / 2);
	return 0;
}