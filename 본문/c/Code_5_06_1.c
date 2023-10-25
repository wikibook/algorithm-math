#include <stdio.h>
#include <stdbool.h>

// 작은 문제 t를 푸는 함수
bool small_problem(int A, int B, int t) {
	int cl = (A + t - 1) / t; // A÷t의 소수점 아래를 자릅니다.
	int cr = B / t; // B÷t의 소수점 아래를 자릅니다.
	if (cr - cl >= 1) return true;
	return false;
}

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	int answer = 0;
	int i;
	for (i = 1; i <= B; i++) {
		if (small_problem(A, B, i) == true) {
			answer = i;
		}
	}
	printf("%d\n", answer);
	return 0;
}
