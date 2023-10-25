#include <stdio.h>
 
int compare_values(const void* a, const void* b) {
	// a가 앞에 있으면 양수,
	// b가 앞에 있으면 음수,
	// a와 b가 같은 값이면 0을 리턴하는 함수
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return +1;
	return 0;
}

long long N;
long long A[100009], B[100009];
 
int main() {
	// 입력
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	
	// 정렬
	qsort(A + 1, N, sizeof(long long), compare_values);
	qsort(B + 1, N, sizeof(long long), compare_values);
	
	// 답 구하기
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] >= B[i]) Answer += (A[i] - B[i]);
		else Answer += (B[i] - A[i]);
	}
	printf("%lld\n", Answer);
	return 0;
}