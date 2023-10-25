#include <stdio.h>

int main() {
	// 입력
	int N, K, A[59];
	scanf("%d%d", &N, &K);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// 수열 요소의 총합 sum 구하기
	int sum = 0;
	for (i = 1; i <= N; i++) {
		sum += A[i];
	}

	// 답 출력
	if (sum % 2 != K % 2) {
		printf("No\n");
	}
	else if (sum > K) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}
