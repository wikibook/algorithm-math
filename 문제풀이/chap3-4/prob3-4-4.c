#include <stdio.h>

int N;
double Answer = 0;

int main() {
	// 입력
	scanf("%d", &N);
	
	// 기댓값 구하기
	for (int i = N; i >= 1; i--) {
		Answer += 1.0 * N / i;
	}
	
	// 출력
	printf("%.12lf\n", Answer);
	return 0;
}