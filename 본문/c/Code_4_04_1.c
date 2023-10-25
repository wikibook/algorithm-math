#include <stdio.h>
#include <stdbool.h>

int N; bool prime[100000009];

int main() {
	// 입력 → 배열 초기화
	scanf("%d", &N);
	int i, x;
	for (i = 2; i <= N; i++) {
		prime[i] = true;
	}

	// 에라토스테네스의 체
	for (i = 2; i * i <= N; i++) {
		if (prime[i] == true) {
			for (x = 2 * i; x <= N; x += i) {
				prime[x] = false;
			}
		}
	}

	// N 이하의 소수를 오름차순으로 출력
	for (i = 2; i <= N; i++) {
		if (prime[i] == true) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
