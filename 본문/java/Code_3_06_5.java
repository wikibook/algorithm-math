import java.util.*;

class Code_3_06_5 {
	static int N;
	static int[] A;
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 재귀함수 호출 → 답 출력
		int answer = solve(1, N + 1);
		System.out.println(answer);
	}
	static int solve(int l, int r) {
		if (r - l == 1) {
			return A[l];
		}
		int m = (l + r) / 2; // 구간 [l, r)의 중앙을 기준으로 분할 정복
		int s1 = solve(l, m); // s1는 A[l] + ... + A[m-1]의 합계를 계산
		int s2 = solve(m, r); // s2는 A[m] + ... + A[r-1]는 합계를 계산
		return s1 + s2;
	}
}
