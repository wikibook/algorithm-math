#include <stdio.h>
#include <stdbool.h>

// 2 이상의 정수 N을 매개변수로 받고, N이 소수라면 True를,
// 아니라면 False를 리턴하는 함수
bool isprime(long long N) {
	long long i;
	for (i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long N;
	scanf("%lld", &N);
	if (isprime(N) == true) {
		printf("prime\n");
	}
	else {
		printf("not prime\n");
	}
	return 0;
}
