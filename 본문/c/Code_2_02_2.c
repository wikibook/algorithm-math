#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b); // a와 b를 입력
	printf("%d\n", a & b); // a AND b의 값을 출력
	printf("%d\n", a | b); // a OR b의 값을 출력
	printf("%d\n", a ^ b); // a XOR b의 값을 출력
	return 0;
}
