#include <stdio.h>

long long N;
long long F[10000009];
long long Answer = 0;

int main() {
	// 입력 → 배열 초기화
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) F[i] = 0;
	
	// F[1], F[2], ..., F[N]를 계산하기
	for (int i = 1; i <= N; i++) {
		// F[i], F[2i], F[3i], ...에 1을 추가
		for (int j = i; j <= N; j += i) F[j] += 1;
	}
	
	// 답 구하기 → 출력
	for (int i = 1; i <= N; i++) {
		Answer += 1LL * i * F[i];
	}
	printf("%lld\n", Answer);
	return 0;
}