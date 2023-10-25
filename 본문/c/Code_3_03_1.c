#include <stdio.h>

int main() {
	// 입력
	int N, A[109];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// 5개의 카드 번호(i, j, k, l, m)를 전체 탐색
	int answer = 0;
	int i, j, k, l, m;
	for (i = 1; i <= N; i++) {
		for (j = i + 1; j <= N; j++) {
			for (k = j + 1; k <= N; k++) {
				for (l = k + 1; l <= N; l++) {
					for (m = l + 1; m <= N; m++) {
						if (A[i] + A[j] + A[k] + A[l] + A[m] == 1000) {
							answer += 1;
						}
					}
				}
			}
		}
	}
	
	// 출력
	printf("%d\n", answer);
	return 0;
}
