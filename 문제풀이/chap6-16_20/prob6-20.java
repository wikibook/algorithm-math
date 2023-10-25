import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] C = new int[N + 1];
		int[] P = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			C[i] = sc.nextInt();
			P[i] = sc.nextInt();
		}
	
		// 누적합 구하기
		int[] S1 = new int[N + 1];
		int[] S2 = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			S1[i] = S1[i - 1] + (C[i] == 1 ? P[i] : 0);
		}
		for (int i = 1; i <= N; i++) {
			S2[i] = S2[i - 1] + (C[i] == 2 ? P[i] : 0);
		}
	
		// 답 출력
		int Q = sc.nextInt();
		for (int i = 1; i <= Q; i++) {
			int L = sc.nextInt();
			int R = sc.nextInt();
			System.out.format("%d %d\n", S1[R] - S1[L - 1], S2[R] - S2[L - 1]);
		}
	}
}