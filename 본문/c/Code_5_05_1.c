#include <stdio.h>

int main() {
	// 입력
	long long a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	
	// 답 구하기(answer는 일단 나올 수 없는 값을 설정)
	long long answer = -(1LL << 62);
	if (answer < a * c) answer = a * c;
	if (answer < a * d) answer = a * d;
	if (answer < b * c) answer = b * c;
	if (answer < b * d) answer = b * d;
	
	// 출력
	printf("%lld\n", answer);
	return 0;
}
