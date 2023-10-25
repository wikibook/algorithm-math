#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// 두 long long 자료형을 비교하는 함수(Code_3_06_1.c 참고)
	if (*(long long*)a < *(long long*)b) return -1;
	if (*(long long*)a > *(long long*)b) return +1;
	return 0;
}

int N; long long X, A[1000009];

int main() {
	// 입력
	scanf("%d%lld", &N, &X);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	// 배열 정렬(Code_3_06_1.c 참고)
	qsort(A + 1, N, sizeof(long long), compare_values);

	// 이진 탐색
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2; // 탐색 범위 중앙으로 분할하기
		if (A[mid] == X) {
			printf("Yes\n");
			return 0;
		}
		if (A[mid] > X) right = mid - 1; // 탐색 범위를 앞부분으로 변경
		if (A[mid] < X) left = mid + 1; // 탐색 범위를 뒷부분으로 변경
	}

	// 더 이상 탐색할 것이 없는 경우도 No를 출력
	printf("No\n");
	return 0;
}
