#include <stdio.h>

int main() {
	// 입력
	int N;
	scanf("%d", &N);
	
	// 답 계산
	long long Answer = 1;
	for (int i = 2; i <= N; i++) Answer *= i;
	
	// 출력
	printf("%lld\n", Answer);
	return 0;
}