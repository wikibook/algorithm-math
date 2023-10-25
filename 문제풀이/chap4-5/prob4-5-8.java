import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		
		// 인접리스트 작성
		ArrayList<PairInt>[] G = new ArrayList[K];
		for (int i = 0; i < K; i++) {
			G[i] = new ArrayList<PairInt>();
		}
		
		// 그래프 엣지 추가
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				G[i].add(new PairInt((i * 10 + j) % K, j));
			}
		}
		
		// 다익스트라 알고리즘: 배열 초기화 등
		int[] dist = new int[K];
		boolean[] used = new boolean[K];
		for (int i = 0; i < K; i++) {
			dist[i] = (1 << 30);
			used[i] = false;
		}
		Queue<PairInt> Q = new PriorityQueue<PairInt>();
		Q.add(new PairInt(0, 0)); // 여기에서 dist[0] = 0로는 되지 않으므로 주의
		
		// 다익스트라 알고리즘: 우선순위 큐 활용
		while (Q.size() >= 1) {
			int pos = Q.poll().second;
			if (used[pos] == true) {
				continue;
			}
			used[pos] = true;
			for (PairInt i : G[pos]) {
				int to = i.first;
				int cost = dist[pos] + i.second;
				if (pos == 0) {
					cost = i.second; // 정점 0의 경우는 제외
				}
				if (dist[to] > cost) {
					dist[to] = cost;
					Q.add(new PairInt(dist[to], to));
				}
			}
		}
		
		// 답 출력
		System.out.println(dist[0]);
	}
	
	// int 자료형 쌍을 다룰 수 있는 PairInt 클래스
	static class PairInt implements Comparable<PairInt> {
		int first, second;
		public PairInt(int first_, int second_) {
			super();
			this.first = first_;
			this.second = second_;
		}
		@Override public int compareTo(PairInt p) {
			// PairInt 자료형끼리 비교하는 함수 
			if (this.first < p.first || (this.first == p.first && this.second < p.second)) {
				return -1;
			}
			if (this.first > p.first || (this.first == p.first && this.second > p.second)) {
				return 1;
			}
			return 0;
		}
	}
}
