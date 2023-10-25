import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] B = new int[N];
		for (int i = 1; i <= N - 1; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		
		// 인접리스트 작성
		G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= N - 1; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 깊이 우선 탐색을 사용한 동적계획법
		visited = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		dp = new int[N + 1];
		dfs(1);

		// 답을 계산하고 출력
		long answer = 0;
		for (int i = 2; i <= N; i++) {
			answer += (long)dp[i] * (N - dp[i]);
		}
		System.out.println(answer);
	}
	
	static boolean[] visited;
	static int[] dp;
	static ArrayList<Integer>[] G;
	static void dfs(int pos) {
		visited[pos] = true;
		dp[pos] = 1;
		for (int i : G[pos]) {
			if (visited[i] == false) {
				dfs(i);
				dp[pos] += dp[i];
			}
		}
	}
}