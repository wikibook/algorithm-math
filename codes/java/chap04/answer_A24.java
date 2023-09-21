import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 배열 등의 정의
		int LEN = 0; // LEN은 L의 길이(예: L[4]까지 쓰여 있는 경우 LEN=4)
		ArrayList<Integer> L = new ArrayList<Integer>();

		// 동적 계획 알고리즘（배열 dp를 사용하지 않는 구현）
		for (int i = 1; i <= N; i++) {
			int pos = ~Collections.binarySearch(L, A[i], (x, y) -> x.compareTo(y) >= 0 ? 1 : -1);

			// L의 최대 값보다 A[i]가 더 큰 경우
			if (pos >= LEN) {
				LEN += 1;
				L.add(A[i]);
			}
			// 그렇지 않은 경우
			else {
				L.set(pos, A[i]);
			}
		}

		// 답을 출력
		System.out.println(LEN);
	}
};
