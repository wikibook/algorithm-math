import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 배열 T 작성 및 중복 삭제
		HashSet<Integer> tmp = new HashSet<Integer>();
		for (int i = 1; i <= N; i++) tmp.add(A[i]);
		ArrayList<Integer> T = new ArrayList<>(tmp);
		Collections.sort(T);

		// 답을 구한다
		int[] B = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			B[i] = ~Collections.binarySearch(T, A[i], (x, y) -> x.compareTo(y) >= 0 ? 1 : -1);
			B[i] += 1;
		}

		// 답을 공백으로 구분해서 출력
		for (int i = 1; i <= N; i++) {
			if (i >= 2) System.out.print(" ");
			System.out.print(B[i]);
		}
		System.out.println();
	}
};
