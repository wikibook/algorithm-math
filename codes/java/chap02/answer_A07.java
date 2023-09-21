import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int D = sc.nextInt();
		int N = sc.nextInt();
		int[] B = new int[D + 2];
		int[] L = new int[N + 1];
		int[] R = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}

		// 전일 비에 더한다
		for (int d = 1; d <= D; d++) B[d] = 0;
		for (int i = 1; i <= N; i++) {
			B[L[i]] += 1;
			B[R[i] + 1] -= 1;
		}

		// 누적 합을 구한다 → 출력
		int[] Answer = new int[D + 2];
		Answer[0] = 0;
		for (int d = 1; d <= D; d++) Answer[d] = Answer[d - 1] + B[d];
		for (int d = 1; d <= D; d++) System.out.println(Answer[d]);
	}
};
