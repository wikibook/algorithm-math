import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입출력을 위해 Scanner 대신 BufferedReader를 사용)
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
		
		// 인접 리스트 생성
		G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 깊이 우선 탐색
		visited = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		dfs(1);

		// 연결 여부 판단(answer = true인 경우 연결)
		boolean answer = true;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false) {
				answer = false;
			}
		}

		// 답 출력
		if (answer == true) {
			System.out.println("The graph is connected.");
		}
		else {
			System.out.println("The graph is not connected.");
		}
	}
	
	static boolean[] visited; // 노드 x가 파란색일 경우, visited[x] = true
	static ArrayList<Integer>[] G;
	static void dfs(int pos) { // pos는 현재 위치
		visited[pos] = true;
		for (int i : G[pos]) {
			if (visited[i] == false) {
				dfs(i);
			}
		}
	}
}