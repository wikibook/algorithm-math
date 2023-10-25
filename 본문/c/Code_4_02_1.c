#include <stdio.h>

int N, A[100009], B[100009];
int Q, L[100009], R[100009];

int main() {
	// 입력
	scanf("%d%d", &N, &Q);
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (j = 1; j <= Q; j++) {
		scanf("%d%d", &L[j], &R[j]);
	}
	
	// 누적합 구하기
	B[0] = 0;
	for (i = 1; i <= N; i++) {
		B[i] = B[i - 1] + A[i];
	}

	// 답 출력
	for (j = 1; j <= Q; j++) {
		printf("%d\n", B[R[j]] - B[L[j] - 1]);
	}
	return 0;
}
