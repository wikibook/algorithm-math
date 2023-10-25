#include <stdio.h>
#include <stdbool.h>
 
long long N, K;
long long A[200009];
long long First[200009], Second[200009];
 
int main() {
	// 입력
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	
	// 배열 초기화
	for (int i = 1; i <= N; i++) First[i] = -1;
	for (int i = 1; i <= N; i++) Second[i] = -1;
	
	// 답 구하기
	// cur은 현재 있는 마을의 번호
	long long cnt = 0, cur = 1;
	while (true) {
		// First, Second 변경
		if (First[cur] == -1) First[cur] = cnt;
		else if (Second[cur] == -1) Second[cur] = cnt;
		
		// K회 이동 후에 마을 cur에 있는지 판정
		if (cnt == K) {
			printf("%lld\n", cur);
			return 0;
		}
		else if (Second[cur] != -1 && (K - First[cur]) % (Second[cur] - First[cur]) == 0) {
			printf("%lld\n", cur);
			return 0;
		}
		
		// 위치 변경
		cur = A[cur];
		cnt += 1;
	}
	return 0;
}