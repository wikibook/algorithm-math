import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		int[] C = new int[N + 1];
		int[] D = new int[N + 1];
		for (int x = 1; x <= N; x++) A[x] = sc.nextInt();
		for (int y = 1; y <= N; y++) B[y] = sc.nextInt();
		for (int z = 1; z <= N; z++) C[z] = sc.nextInt();
		for (int w = 1; w <= N; w++) D[w] = sc.nextInt();

		// 배열 P를 작성
		ArrayList<Integer> P = new ArrayList<Integer>();
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) P.add(A[x] + B[y]);
		}

		// 배열 Q를 작성
		ArrayList<Integer> Q = new ArrayList<Integer>();
		for (int z = 1; z <= N; z++) {
			for (int w = 1; w <= N; w++) Q.add(C[z] + D[w]);
		}

		// 배열 Q를 오름차순으로 정렬
		Collections.sort(Q);

		// 바이너리 서치(배열 P, Q가 0번부터 시작한다는 점에 유의하세요!)
		for (int i = 0; i < N * N; i++) {
			int pos1 = ~Collections.binarySearch(Q, K - P.get(i), (x, y) -> x.compareTo(y) >= 0 ? 1 : -1);
			if (pos1 < N * N && Q.get(pos1) == K - P.get(i)) {
				System.out.println("Yes");
				System.exit(0);
			}
		}

		// 발견하지 못한 경우
		System.out.println("No");
	}
};
