#include <stdio.h>

int main() {
	// 입력
	int N, S;
	scanf("%d%d", &N, &S);
	
	// 답 구하기
	int answer = 0;
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i + j <= S) {
				answer += 1;
			}
		}
	}
	
	// 출력
	printf("%d\n", answer);
}
