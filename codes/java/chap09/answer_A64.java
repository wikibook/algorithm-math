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
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] = Integer.parseInt(st.nextToken());
		}
		
		// 인접 리스트 생성
		ArrayList<Edge>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Edge>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(new Edge(B[i], C[i]));
			G[B[i]].add(new Edge(A[i], C[i]));
		}
		
		// 배열 초기화
		final int INF = 2000000000;
		boolean[] kakutei = new boolean[N + 1]; // Java에서 new로 초기화한 배열의 요소는 false가 된다는 점에 유의하세요.
		int[] cur = new int[N + 1];
		Arrays.fill(cur, INF);

		// 시작 지점을 큐에 추가
		cur[1] = 0;
		Queue<State> Q = new PriorityQueue<>();
		Q.add(new State(cur[1], 1));

		// 데이크스트라 알고리즘
		while (Q.size() >= 1) {
			// 다음에 확정할 노드를 구한다
			// (여기서는 우선순위 큐 Q의 최소 요소 Q를 가져와서 Q에서 제거)
			int pos = Q.remove().pos;

			// Q의 최소 요소가 '이미 확정한 노드'인 경우
			if (kakutei[pos]) {
				continue;
			}

			// cur[x] 값을 업데이트한다
			kakutei[pos] = true;
			for (int i = 0; i < G[pos].size(); i++) {
				Edge e = G[pos].get(i);
				if (cur[e.to] > cur[pos] + e.cost) {
					cur[e.to] = cur[pos] + e.cost;
					Q.add(new State(cur[e.to], e.to));
				}
			}
		}
		
		// 답을 출력(빠른 출력을 위해 System.out.println이 아닌 PrintWriter를 사용)
		PrintWriter output = new PrintWriter(System.out);
		for (int i = 1; i <= N; i++) {
			if (cur[i] != INF) {
				output.println(cur[i]);
			}
			else {
				output.println("-1");
			}
		}
		output.flush();
	}

	// 가중치 그래프의 에지 클래스 Edge
	static class Edge {
		int to, cost; // 목적지 to, 길이 cost
		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	// 데이크스트라 알고리즘의 (cur[x], x)를 관리하는 클래스 (cur[x] = dist, x = pos에 대응)
	static class State implements Comparable<State> {
		int dist, pos;
		public State(int dist, int pos) {
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
