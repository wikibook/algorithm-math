#include <stdio.h>

int N, Q, C[100009], P[100009], L[100009], R[100009], S1[100009], S2[100009];

int main() {
	// 입력
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d%d", &C[i], &P[i]);
	}

	// 누적합 구하기
	for (i = 1; i <= N; i++) {
		S1[i] = S1[i - 1] + (C[i] == 1 ? P[i] : 0);
	}
	for (i = 1; i <= N; i++) {
		S2[i] = S2[i - 1] + (C[i] == 2 ? P[i] : 0);
	}

	// 답 출력
	scanf("%d", &Q);
	for (i = 1; i <= Q; i++) {
		scanf("%d%d", &L[i], &R[i]);
		printf("%d %d\n", S1[R[i]] - S1[L[i] - 1], S2[R[i]] - S2[L[i] - 1]);
	}
	return 0;
}