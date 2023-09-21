import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[N + 1];
		int[] X = new int[M + 1];
		int[] Y = new int[M + 1];
		int[] Z = new int[M + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		for (int i = 1; i <= M; i++) {
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
			Z[i] = sc.nextInt();
		}

		// 인접 리스트를 생성하고 그래프에 에지를 추가
		ArrayList<Integer>[] G = new ArrayList[1 << N];
		for (int i = 0; i < (1 << N); i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < (1 << N); i++) {
			for (int j = 1; j <= M; j++) {
				int nextState = getNext(N, i, X[j], Y[j], Z[j]);
				G[i].add(nextState);
			}
		}

		// 시작과 끝의 정점 번호 찾기
		int start = 0;
		for (int i = 1; i <= N; i++) {
			if (A[i] == 1) {
				start += (1 << (i - 1));
			}
		}
		int goal = (1 << N) - 1;

		// 배열 초기화／시작 시점을 큐에 넣는다
		int[] dist = new int[1 << N];
		Arrays.fill(dist, -1);
		dist[start] = 0;
		Queue<Integer> Q = new LinkedList<>();
		Q.add(start);

		// 너비 우선 탐색
		while (Q.size() >= 1) {
			int pos = Q.remove();
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex);
				}
			}
		}

		// 답을 출력
		System.out.println(dist[goal]);
	}
	
	// 정점 pos의 상태에서 '램프 x, y, z의 상태'를 반전시켰을 때 정점 번호를 반환하는 함수
	// (책에 있는 코드에서는 'vertex pos의 상태에서 idx번째 작업을 수행했을 때'의 정점 번호를 반환하는 함수를 구현하고 있지만, 책에  있는 코드에서는 이와는 조금 다르게 구현하고 있습니다.)
	static int getNext(int N, int pos, int x, int y, int z) {
		// pos의 2진법 표기법을 사용하여 정점 pos가 나타내는 램프의 상태 state를 계산합니다.
		// (2진법으로 변환하는 방법은 1.4절 참조)
		int[] state = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			int wari = (1 << (i - 1));
			state[i] = (pos / wari) % 2;
		}

		// 램프 x, y, z 상태 반전
		state[x] = 1 - state[x];
		state[y] = 1 - state[y];
		state[z] = 1 - state[z];

		// 10진법으로 변환하는 방법도 1.4절을 참조
		int ret = 0;
		for (int i = 1; i <= N; i++) {
			if (state[i] == 1) {
				ret += (1 << (i - 1));
			}
		}
		return ret;
	}
}

// 참고 1: 이 문제에 대한 더 간결한 구현도 있으니, 원한다면 answer_A70_extra.py도 참고하시기 바랍니다.