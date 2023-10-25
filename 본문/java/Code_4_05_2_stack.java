// 이 코드는 깊이 우선 탐색(DFS)를 스택으로 구현한 예입니다.
// 스택은 "가장 위에 요소를 추가한다", "가장 위의 요소를 확인한다", "가장 위의 요소를 꺼낸다"라는 3가지 조작을 할 수 있는 자료구조입니다.
// 깊이 우선 탐색 부분은 코드 4.5.3의 queue를 stack으로 변경한 것을 기반으로 작성했습니다.

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
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 깊이 우선 탐색 초기화
		boolean[] visited = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		Stack<Integer> S = new Stack<>(); // 스택 S 정의
		visited[1] = true;
		S.push(1); // S에 1을 추가

		// 깊이 우선 탐색
		while (S.size() >= 1) {
			int pos = S.pop(); // S의 앞부분을 확인하고 꺼냄
			for (int nex : G[pos]) {
				if (visited[nex] == false) {
					visited[nex] = true;
					S.push(nex); // S에 nex를 추가
				}
			}
		}
		
		// 연결 판정(answer = true일 때 연결)
		boolean answer = true;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false) {
				answer = false;
			}
		}
		if (answer == true) {
			System.out.println("The graph is connected.");
		}
		else {
			System.out.println("The graph is not connected.");
		}
	}
}