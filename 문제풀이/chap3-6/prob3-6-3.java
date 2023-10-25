import java.util.*;

class Main {
	public static void MergeSort(int[] A, int[] C, int l, int r) {
		// r-l=1이라면 이미 정렬되어 있으므로, 아무것도 하지 않음
		if (r - l == 1) return;
		
		// 2개로 분할하고, 분할한 배열을 정렬함
		int m = (l + r) / 2;
		MergeSort(A, C, l, m);
		MergeSort(A, C, m, r);
		
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
				// 배열 B'가 빈 경우
				C[cnt] = A[c1]; c1++;
			}
			else {
				// 둘 다 아닌 경우
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
		// [C[0], C[1], ..., C[cnt-1]] -> [A[l], A[l+1], ..., A[r-1]]
		for (int i = 0; i < cnt; i++) A[l + i] = C[i];
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 입력
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] C = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// 병합정렬
		MergeSort(A, C, 1, N + 1);
		
		// 출력
		for (int i = 1; i <= N; i++) {
			System.out.println(A[i]);
		}
	}
}