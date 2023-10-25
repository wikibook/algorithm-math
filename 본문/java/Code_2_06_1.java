import java.util.*;

class Code_2_06_1 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 모든 패턴 탐색: (1L << N)은 2의 N제곱
		String answer = "No";
		for (long i = 0; i < (1L << N); i++) {
			int sum = 0;
			for (int j = 1; j <= N; j++) {
				// (i & (1L << (j-1))) != 0L이라면
				// i의 2진법 표기에서 아래에서 j번째 카드가 1이라는 의미입니다.
				// (1L << (j - 1))는 C에서 "2의 j-1제곱을 의미합니다.
				if ((i & (1L << (j - 1))) != 0L) {
					sum += A[j];
				}
			}
			if (sum == S) {
				answer = "Yes";
				break;
			}
		}
		
		// 출력
		System.out.println(answer);
	}
}
