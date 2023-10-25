#include <stdio.h>

int main() {
	// 입력
	int N, X, Y;
	scanf("%d%d%d", &N, &X, &Y);
	
	// 답 구하기
	int cnt = 0;
	int i;
	for (i = 1; i <= N; i++) {
		// mod 계산은 2.2절 참고
		if (i % X == 0 || i % Y == 0) {
			cnt += 1;
		}
	}
	
	// 출력
	printf("%d\n", cnt);
	
	return 0;
}
