import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		N = sc.nextInt();
		X = sc.nextInt();
		A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 바이너리 서치를 수행한다
		int Answer = search(X);
		System.out.println(Answer);
	}

	static int N, X;
	static int[] A;
	
	// 정수 x가 몇 번째에 위치하는지 반환한다
	static int search(int x) {
		int L = 1, R = N;
		while (L <= R) { // 탐색 범위가 없어질 때까지 계속 비교한다
			int M = (L + R) / 2;
			if (x < A[M]) R = M - 1;
			if (x == A[M]) return M;
			if (x > A[M]) L = M + 1;
		}
		return -1; // 정수 x가 존재하지 않는다(주: 이 문제의 조건에서 -1이 반환되는 일은 없다)
	}
};
