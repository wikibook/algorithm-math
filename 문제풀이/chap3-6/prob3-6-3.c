#include <stdio.h>

int N, A[200009], C[200009];

// A[l], A[l+1], ..., A[r−1]를 오름차순으로 정렬하는 함수
void MergeSort(int l, int r) {
	// r−l=1이라면 이미 정렬되어 있으므로, 아무것도 하지 않음
	if (r - l == 1) return;
	
	// 2개로 분할하고, 분할한 배열을 정렬함
	int m = (l + r) / 2;
	MergeSort(l, m);
	MergeSort(m, r);
	
	// 이 시점에서 다음 두 배열이 정렬 완료됨
	// 배열 A' [A[l], A[l+1], ..., A[m−1]]
	// 배열 B' [A[m], A[m+1], ..., A[r−1]]
	// 다음 코드들은 Merge 조작에 해당하는 부분
	int c1 = l, c2 = m, cnt = 0;
	while (c1 != m || c2 != r) {
		if (c1 == m) {
			// 배열 A'가 빈 경우
			C[cnt] = A[c2]; c2++;
		}
		else if (c2 == r) {
			// 배열 B'가 빈 경우(빠진 부분)
			C[cnt] = A[c1]; c1++;
		}
		else {
			// 모두 아닌 경우(빠진 부분)
			if (A[c1] <= A[c2]) {
				C[cnt] = A[c1]; c1++;
			}
			else {
				C[cnt] = A[c2]; c2++;
			}
		}
		cnt++;
	}
	
	// 배열 A', 배열B'를 Merge한 배열 C를 A에 하나하나 할당
	// [C[0], ..., C[cnt−1]] −> [A[l], ..., A[r−1]]
	for (int i = 0; i < cnt; i++) A[l + i] = C[i];
}

int main() {
	// 입력
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	
	// 병합정렬 → 답 출력
	MergeSort(1, N + 1);
	for (int i = 1; i <= N; i++) printf("%d\n", A[i]);
	return 0;
}