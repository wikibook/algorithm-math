import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		for (int i = 2; i <= N; i++) A[i] = sc.nextInt();
		for (int i = 3; i <= N; i++) B[i] = sc.nextInt();

		// 동적 계획 알고리즘
		int[] dp = new int[N + 1];
		dp[1] = 0;
		dp[2] = A[2];
		for (int i = 3; i <= N; i++) {
			dp[i] = Math.min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
		}

		// 답의 복원
		// 변수 Place는 현재 위치(목표부터 진행한다)
		// 예를 들어, 입력 예의 경우 Place는 5 → 4 → 2 → 1로 변화한다
		ArrayList<Integer> Answer = new ArrayList<Integer>();
		int Place = N;
		while (true) {
			Answer.add(Place);
			if (Place == 1) break;

			// 어디에서 방 Place로 이동하는 것이 최적인지 구한다
			if (dp[Place - 1] + A[Place] == dp[Place]) Place = Place - 1;
			else Place = Place - 2;
		}

		// 출력
		System.out.println(Answer.size());
		for (int i = Answer.size() - 1; i >= 0; i--) {
			if (i < Answer.size() - 1) System.out.print(" ");
			System.out.print(Answer.get(i));
		}
		System.out.println();
	}
};
