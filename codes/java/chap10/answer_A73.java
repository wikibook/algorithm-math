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
		int[] C = new int[M + 1];
		int[] D = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] = Integer.parseInt(st.nextToken());
			D[i] = Integer.parseInt(st.nextToken());
		}
		
		// 그래프 작성
		ArrayList<Edge>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Edge>();
		}
		for (int i = 1; i <= M; i++) {
			if (D[i] == 1) {
				G[A[i]].add(new Edge(B[i], 10000L * C[i] - 1L));
				G[B[i]].add(new Edge(A[i], 10000L * C[i] - 1L));
			}
			else {
				G[A[i]].add(new Edge(B[i], 10000L * C[i]));
				G[B[i]].add(new Edge(A[i], 10000L * C[i]));
			}
		}
		
		// 데이크스트라 알고리즘(데이크스트라 알고리즘에 대한 자세한 설명은 이 책의 9.4절 및 . /chap09/answer_A64.java 참조)
		final long INF = (1L << 60);
		boolean[] kakutei = new boolean[N + 1];
		long[] cur = new long[N + 1];
		Arrays.fill(cur, INF);
		cur[1] = 0;
		Queue<State> Q = new PriorityQueue<>();
		Q.add(new State(cur[1], 1));
		while (Q.size() >= 1) {
			int pos = Q.remove().pos;
			if (kakutei[pos]) {
				continue;
			}
			kakutei[pos] = true;
			for (int i = 0; i < G[pos].size(); i++) {
				Edge e = G[pos].get(i);
				if (cur[e.to] > cur[pos] + e.cost) {
					cur[e.to] = cur[pos] + e.cost;
					Q.add(new State(cur[e.to], e.to));
				}
			}
		}
		
		// 답을 출력
		// 마라톤 코스의 거리: cur[N]/10000을 소수점 이하를 자른 값
		// 코드상 나무의 수: cur[N]과 Distance*10000의 차이
		long distance = (cur[N] + 9999) / 10000;
		long numTrees = distance * 10000 - cur[N];
		System.out.println(distance + " " + numTrees);
	}

	// 가중치 그래프의 에지 클래스 Edge
	static class Edge {
		int to; long cost; // 行き先 to、長さ cost
		public Edge(int to, long cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	// 데이크스트라 알고리즘의 (cur[x], x)를 관리하는 클래스 (cur[x] = dist, x = pos에 대응)
	static class State implements Comparable<State> {
		long dist; int pos;
		public State(long dist, int pos) {
			this.dist = dist;
			this.pos = pos;
		}
		@Override public int compareTo(State s) {
			// State 타입끼리 비교하는 함수
			if (this.dist < s.dist) {
				return -1;
			}
			if (this.dist > s.dist) {
				return 1;
			}
			return 0;
		}
	}
}