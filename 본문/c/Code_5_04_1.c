#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b) {
	return (a < b ? a : b);
}

int maximum(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	// 입력
	int N, K;
	scanf("%d%d", &N, &K);

	// 사건B의 개수를 yeosagun(여사건) 변수로 셉니다.
	long long yeosagun = 0;
	int a, b, c;
	for (a = 1; a <= N; a++) {
		int l = maximum(a - (K - 1), 1); // b, c의 탐색 범위 하한 l
		int r = minimum(a + (K - 1), N); // b, c의 탐색 범위 상한 r
		for (b = l; b <= r; b++) {
			for (c = l; c <= r; c++) {
				if (abs(b - c) <= K - 1) yeosagun += 1;
			}
		}
	}
	
	// 답 출력
	printf("%lld\n", (long long)N * N * N - yeosagun);
	return 0;
}
