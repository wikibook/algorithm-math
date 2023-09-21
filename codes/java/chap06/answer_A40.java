import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 개수를 센다
		long[] cnt = new long[101];
		for (int i = 1; i <= 100; i++) cnt[i] = 0;
		for (int i = 1; i <= N; i++) cnt[A[i]] += 1;

		// 답을 구한다
		// nC3 = n * (n-1) * (n-2) / 6 을 사용한다
		long Answer = 0;
		for (int i = 1; i <= 100; i++) {
			Answer += cnt[i] * (cnt[i]-1) * (cnt[i]-2) / 6;
		}
		System.out.println(Answer);
	}
};
