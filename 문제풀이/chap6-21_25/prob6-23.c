#include <stdio.h>
#include <stdbool.h>

long long L, R; bool isprime[500009];

int main() {
	// 입력
	scanf("%lld%lld", &L, &R);

	// 배열 초기화
	long long i, j;
	for (i = 0; i <= R - L; i++) {
		isprime[i] = true;
	}

	// L = 1  때의 조건 분기(코너 케이스)
	if (L == 1) {
		isprime[0] = false;
	}

	// 에라토스테네스의 체
	for (i = 2; i * i <= R; i++) {
		long long min_value = ((L + i - 1) / i) * i; // L 이상에서 최소인 i의 배수
		// L 이상 R 이하에서 i를 제외한 i의 배수에 X 표시
		for (j = min_value; j <= R; j += i) {
			if (j == i) continue;
			isprime[j - L] = false;
		}
	}

	// 갯수 세서 출력하기
	long long answer = 0;
	for (i = 0; i <= R - L; i++) {
		if (isprime[i] == true) {
			answer += 1;
		}
	}
	printf("%lld\n", answer);
	return 0;
}