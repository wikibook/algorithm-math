#include <stdio.h>

long long n, r;
long long Fact_n = 1;
long long Fact_r = 1;
long long Fact_nr = 1;

int main() {
	// 입력
	scanf("%lld%lld", &n, &r);
	
	// 팩토리얼 구하기
	for (int i = 1; i <= n; i++) Fact_n *= i;
	for (int i = 1; i <= r; i++) Fact_r *= i;
	for (int i = 1; i <= n - r; i++) Fact_nr *= i;
	
	// 출력
	printf("%lld\n", Fact_n / (Fact_r * Fact_nr));
	return 0;
}