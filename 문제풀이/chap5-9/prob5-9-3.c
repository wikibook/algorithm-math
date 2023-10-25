#include <stdio.h>
 
// Movie 자료형
struct Movie {
	int l, r;
};

// r을 기준으로 크기를 비교하는 함수
int compare_values(const void* a, const void* b) {
	// a.r이 앞에 있으면 양수,
	// b.r이 앞에 있으면 음수,
	// a.r와 b.r이 같은 값이면 0을 리턴하는 함수
	struct Movie A = *(const struct Movie*)a;
	struct Movie B = *(const struct Movie*)b;
	if (A.r < B.r) return -1;
	else if (A.r > B.r) return +1;
	return 0;
}

int N;
struct Movie A[300009];
int CurrentTime = 0; // 현재 시각(마지막에 선택한 영화의 종료 시각)
int Answer = 0; // 현재까지 본 영화 수
 
int main() {
	// 입력
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d%d", &A[i].l, &A[i].r);
	
	// 정렬
	qsort(A + 1, N, sizeof(*A), compare_values);
	
	// 종료 시각이 가장 빠른 것 선택하기를 반복함
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= A[i].l) {
			CurrentTime = A[i].r;
			Answer += 1;
		}
	}
	
	// 출력
	printf("%d\n", Answer);
	return 0;
}