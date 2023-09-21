import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int[] A = new int[N + 1];
		int[] S = new int[N + 1];
		int[] L = new int[Q + 1];
		int[] R = new int[Q + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		for (int j = 1; j <= Q; j++) {
			L[j] = sc.nextInt();
			R[j] = sc.nextInt();
		}

		// 누적 합 계산
		S[0] = 0;
		for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

		// 질문에 답한다
		for (int j = 1; j <= Q; j++) {
			System.out.println(S[R[j]] - S[L[j] - 1]);
		}
	}
};
