#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// a가 앞에 있으면 양수,
	// b가 앞에 있으면 음수,
	// a와 b가 같은 값이면 0을 리턴하는 함수
	if (*(long long*)a < *(long long*)b) return -1;
	if (*(long long*)a > *(long long*)b) return +1;
	return 0;
}

// 각 자릿수 곱의 후보
int cand_size = 0;
long long fm_cand[10000000];

// m의 각 자릿수 곱을 리턴하는 함수
long long product(long long m) {
	long long ans = 1;
	if (m == 0) ans = 0;
	while (m >= 1) {
		ans *= (m % 10);
		m /= 10;
	}
	return ans;
}

// m의 자릿수는 11자리 이하
void func(int digit, long long m) {
	if (digit == 11) {
		fm_cand[cand_size] = product(m);
		cand_size += 1;
		return;
	}
 
	// 다음 자리 탐색
	// min_value은 cur의 마지막 자리(숫자가 오름차순으로 정렬되어 있으므로, 다음 자리는 이전 자리보다 크거나 같을 것입니다).
	int min_value = (m % 10);
	for (int i = min_value; i <= 9; i++) {
		func(digit + 1, 10LL * m + 1LL * i);
	}
}
 
int main() {
	// f(m) 후보 나열
	for (int i = 0; i <= 9; i++) {
		func(1, i);
	}
 
	// fm_cand 정렬하기
	qsort(fm_cand, cand_size, sizeof(long long), compare_values);
 
	// 입력
	long long N, B;
	scanf("%lld%lld", &N, &B);
 
	// m - f(m) = B이 되는지 확인
	long long Answer = 0;
	for (int i = 0; i < cand_size; i++) {
		if (i >= 1 && fm_cand[i - 1] == fm_cand[i]) {
			// 이전에 확인했던 요소는 확인하지 않음
			continue;
		}
		long long m = fm_cand[i] + B;
		long long prod_m = product(m);
		if (prod_m == fm_cand[i] && m <= N) {
			Answer += 1;
		}
	}
 
	// 출력
	printf("%lld\n", Answer);
	return 0;
}