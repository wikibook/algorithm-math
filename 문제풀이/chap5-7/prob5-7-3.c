#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// a가 앞에 있으면 양수,
	// b가 앞에 있으면 음수,
	// a와 b가 같은 값이면 0을 리턴하는 함수
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return +1;
	return 0;
}
 
long long N, A[200009];
long long Answer = 0;
 
int main() {
	// 입력
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld\n", &A[i]);
	
	// 정렬(코드 5.7.1에서 추가한 유일한 부분)
	qsort(A + 1, N, sizeof(long long), compare_values);
	
	// 답 구하기 → 답 출력
	for (int i = 1; i <= N; i++) Answer += A[i] * (-N + 2LL * i - 1LL);
	printf("%lld\n", Answer);
	return 0;
}