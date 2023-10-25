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

long long N;
long long X[200009], Y[200009];

int main() {
	// 입력
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld%lld", &X[i], &Y[i]);
	
	// 배열 정렬하기
	qsort(X + 1, N, sizeof(long long), compare_values);
	qsort(Y + 1, N, sizeof(long long), compare_values);
	
	// Part1의 답(x 좌표 차의 절댓값 총합)
	long long Part1 = 0;
	for (int i = 1; i <= N; i++) Part1 += X[i] * (-N + 2LL * i - 1LL);
	
	// Part2의 답(y 좌표 차의 절댓값 총합)
	long long Part2 = 0;
	for (int i = 1; i <= N; i++) Part2 += Y[i] * (-N + 2LL * i - 1LL);
	
	// 출력
	printf("%lld\n", Part1 + Part2);
	return 0;
}