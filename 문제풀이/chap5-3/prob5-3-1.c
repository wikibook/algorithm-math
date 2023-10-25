#include <stdio.h>

int main() {
	// 입력
	long long H, W;
	scanf("%lld%lld", &H, &W);
	
	// 조건 분기
	if (H == 1 || W == 1) {
		printf("1\n");
	}
	else {
		printf("%lld\n", (H * W + 1LL) / 2LL);
	}
	return 0;
}