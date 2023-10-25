import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		for (int i = 1; i <= N; i++) B[i] = sc.nextInt();
		
		// 답 계산/출력
		double Answer = 0.0;
		for (int i = 1; i <= N; i++) {
			Answer += (1.0 / 3.0) * A[i] + (2.0 / 3.0) * B[i];
		}
		System.out.format("%.12f\n", Answer);
	}
}