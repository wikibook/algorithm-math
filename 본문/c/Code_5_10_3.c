#include <stdio.h>

int main() {
	// 입력
	int N; long long X, Y;
	scanf("%d%lld%lld", &N, &X, &Y);

	// 4개의 정수 (a, b, c, d)를 전체 탐색 → 답 출력
	int a, b, c, d;
	for (a = 1; a <= N; a++) {
		for (b = a; b <= N; b++) {
			for (c = b; c <= N; c++) {
				for (d = c; d <= N; d++) {
					if (a + b + c + d == X && 1LL * a * b * c * d == Y) {
						printf("Yes\n");
						return 0; // 프로그램 실행을 종료합니다.
					}
				}
			}
		}
	}
	printf("No\n"); // 하나도 찾지 못했다면 No를 출력
	return 0;
}
