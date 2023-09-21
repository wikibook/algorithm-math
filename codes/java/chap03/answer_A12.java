import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		N = sc.nextInt();
		K = sc.nextInt();
		A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 바이너리 서치
		// Left는 탐색 범위의 왼쪽 끝, Right는 탐색 범위의 오른쪽 끝을 나타낸다
		long Left = 1, Right = 1000000000;
		while (Left < Right) {
			long Mid = (Left + Right) / 2;
			boolean Answer = check(Mid);
			if (Answer == false) Left = Mid + 1; // 답이 Mid+1 이상임을 알 수 있다
			if (Answer == true) Right = Mid; // 답이 Mid 이하임을 알 수 있다
		}

		// 출력(이때, Left=Right가 된다)
		System.out.println(Left);
	}

	static int N, K;
	static int[] A;

	// 답이 x 이하인지 판정하고 Yes라면 true, No라면 false를 반환한다
	static boolean check(long x) {
		long sum = 0;
		for (int i = 1; i <= N; i++) sum += x / (long)A[i]; //'x ÷ A[i]'의 소수점 이하를 버린다
		if (sum >= (long)K) return true;
		return false;
	}
};
