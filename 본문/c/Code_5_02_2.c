#include <stdio.h>

int main() {
	long long N;
	scanf("%lld", &N);
	if (N % 4 == 0) {
		printf("Second\n"); // 후수필승
	}
	else {
		printf("First\n"); // 선수필승
	}
	return 0;
}
