import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 배열 R의 정의
		int[] R = new int[N + 1];

		// 자벌레 알고리즘
		for (int i = 1; i <= N - 1; i++) {
			// 시작 지점을 결정한다
			if (i == 1) R[i] = 1;
			else R[i] = R[i - 1];

			// 한계까지 더해간다
			while (R[i] < N && A[R[i] + 1] - A[i] <= K) {
				R[i] += 1;
			}
		}

		// 출력(답은 최대 50억 정도가 되므로 long형을 사용해야 한다.)
		long Answer = 0;
		for (int i = 1; i <= N - 1; i++) Answer += (R[i] - i);
		System.out.println(Answer);
	}
};
