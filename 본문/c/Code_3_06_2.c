#include <stdio.h>

int N, A[200009];

int main() {
	// 입력
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	// 선택 정렬
	for (i = 1; i <= N - 1; i++) {
		int min_position = i;
		int min_value = A[i];
		for (j = i + 1; j <= N; j++) {
			if (A[j] < min_value) {
				min_position = j; // min_position는 최솟값의 인덱스(1～N)
				min_value = A[j]; // min_value는 현재 시점에서 최소값
			}
		}
		// 다음 3줄로 A[i]와 A[min_position]를 스왑
		int temp = A[i];
		A[i] = A[min_position];
		A[min_position] = temp;
	}

	// 출력
	for (int i = 1; i <= N; i++) {
		printf("%d\n", A[i]);
	}
	return 0;
}
