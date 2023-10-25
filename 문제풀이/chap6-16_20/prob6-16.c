#include <stdio.h>

int main() {
	// 입력
	int N, X;
	scanf("%d%d", &N, &X);

	// 모든 (a, b, c) 조합 확인하기
	int answer = 0;
	int a, b, c;
	for (a = 1; a <= N; a++) {
		for (b = a + 1; b <= N; b++) {
			for (c = b + 1; c <= N; c++) {
				if (a + b + c == X) {
					answer += 1;
				}
			}
		}
	}

	// 답 출력
	printf("%d\n", answer);

	return 0;
}