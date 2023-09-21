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
		// (여기서는 그래프를 실제로 가지고 있지 않고 POS에서 나오는 변을 그대로 계산하여 너비 우선 탐색을 합니다)
		while (Q.size() >= 1) {
			int pos = Q.remove();
			for (int i = 1; i <= M; i++) {
				// 비트 연산의 XOR을 사용하여 연산 후 정점 번호를 구한다(XOR에 대한 설명은 1열 참조).
				// 램프 k를 뒤집는 것은 정점 번호의 2^k의 위치를 뒤집는 것, 즉 2^k를 XOR하는 것과 동일합니다.
				int nex = pos ^ (1 << (X[i] - 1)) ^ (1 << (Y[i] - 1)) ^ (1 << (Z[i] - 1));
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex);
				}
			}
		}

		// 답을 출력
		System.out.println(dist[goal]);
	}
}

// 참고 1: 이 프로그램은 answer_A70.java에 비해 코드가 간결할 뿐만 아니라 실행 속도 면에서도 우수합니다.
// 왜냐하면 인접 리스트를 실제로 만들지 않아도 되고, 배열 state를 만들지 않고 6번의 비트 연산만으로 '다음 정점 번호'를 구할 수 있기 때문입니다.
// 또한, 비트 연산은 곱셈(*)이나 나눗셈(/) 등의 연산에 비해 훨씬 빠릅니다.
