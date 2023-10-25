import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입출력을 위해서, Scanner 대신에 BufferedReader를 사용했습니다)
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
		}
		
		// 인접리스트 작성
		G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 깊이 우선 탐색
		color = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			color[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			if (color[i] == 0) {
				// 정점 i가 흰색인 경우(아직 방문하지 않은 연결 성분인 경우)
				color[i] = 1;
				dfs(i);
			}
		}

		// 이분 그래프인지 판정
		boolean answer = true;
		for (int i = 1; i <= M; i++) {
			if (color[A[i]] == color[B[i]]) {
				answer = false;
			}
		}
		if (answer == true) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
	
	static int[] color;
	static ArrayList<Integer>[] G;
	static void dfs(int pos) {
		for (int i : G[pos]) {
			if (color[i] == 0) {
				// color[pos] = 1일 때 2, color[pos] = 2일 때 1
				color[i] = 3 - color[pos];
				dfs(i);
			}
		}
	}
}
