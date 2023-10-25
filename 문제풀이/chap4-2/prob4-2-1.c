#include <stdio.h>
 
long long N, A[200009], S[200009];
long long M, B[200009];
 
int main() {
	// 입력
	scanf("%lld", &N);
	for (int i = 1; i <= N - 1; i++) scanf("%lld", &A[i]);
	scanf("%lld", &M);
	for (int i = 1; i <= M; i++) scanf("%lld", &B[i]);
	
	// 누적합 구하기
	S[1] = 0;
	for (int i = 2; i <= N; i++) S[i] = S[i - 1] + A[i - 1];
	
	// 답 구하기
	long long Answer = 0;
	for (int i = 1; i <= M - 1; i++) {
		if (B[i] < B[i + 1]) {
			Answer += (S[B[i + 1]] - S[B[i]]);
		}
		else {
			Answer += (S[B[i]] - S[B[i + 1]]);
		}
	}
	
	// 출력
	printf("%lld\n", Answer);
	return 0;
}