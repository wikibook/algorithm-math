#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// a가 앞에 있으면 양수,
	// b가 앞에 있으면 음수,
	// a와 b가 같은 값이면 0을 리턴하는 함수
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return +1;
	return 0;
}

int N, A[200009];

int main() {
	// 입력(예를 들어  N=5, A[1]=3, A[2]=1, A[3]=4, A[4]=1, A[5]=5를 입력한 경우)
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// 정렬(A[1]부터 N개의 요소를 정렬할 것이므로, 매개변수에 A+1, N을 지정합니다).
	// qsort 함수로 배열의 내용이 [3,1,4,1,5]에서 [1,1,3,4,5]로 바뀝니다.
	qsort(A + 1, N, sizeof(int), compare_values);
	
	// 출력(1, 1, 3, 4, 5 순서로 출력됨)
	for (i = 1; i <= N; i++) {
		printf("%d\n", A[i]);
	}
	
	return 0;
}
