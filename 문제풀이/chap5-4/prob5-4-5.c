#include <stdio.h>
 
long long N, K;
long long V[20];
long long Answer = 0;
 
// 최대공약수를 리턴하는 함수
long long GCD(long long A, long long B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}
 
// 최소공배수를 리턴하는 함수
long long LCM(long long A, long long B) {
	return (A / GCD(A, B)) * B;
}
 
int main() {
	// 입력
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= K; i++) scanf("%lld", &V[i]);
 
	// 비트 전체 탐색
	for (int i = 1; i < (1 << K); i++) {
		long long cnt = 0; // 선택된 숫자의 개수
		long long lcm = 1; // 최소공배수
		for (int j = 0; j < K; j++) {
			if ((i & (1 << j)) != 0) {
				cnt += 1;
				lcm = LCM(lcm, V[j + 1]);
			}
		}
		long long num = N / lcm; // 선택된 숫자 모두의 배수인 것의 개수
		if (cnt % 2 == 1) Answer += num;
		if (cnt % 2 == 0) Answer -= num;
	}
 
	// 출력
	printf("%lld\n", Answer);
	return 0;
}