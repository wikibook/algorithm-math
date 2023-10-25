#include <stdio.h>
#include <stdbool.h>

int main() {
	// 입력
	long long N;
	scanf("%lld", &N);
	
	// 소인수분해(공백으로 구분해서 출력)
	bool flag = false;
	for (long long i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			if (flag == true) printf(" ");
			flag = true;
			N /= i;
			printf("%lld", i);
		}
	}
	if (N >= 2) {
		if (flag == true) printf(" ");
		flag = true;
		printf("%lld", N);
	}
	printf("\n");
	return 0;
}