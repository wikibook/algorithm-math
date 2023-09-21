import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력(책과 달리 A[i], B[i]는 0-indexed로 입력합니다.)
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Integer[] A = new Integer[N];
		Integer[] B = new Integer[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		for (int i = 0; i < N; i++) {
			B[i] = sc.nextInt();
		}

		// 배열 정렬
		Arrays.sort(A);
		Arrays.sort(B, Collections.reverseOrder());

		// 해답을 찾아 출력
		int answer = 0;
		for (int i = 0; i < N; i++) {
			answer += A[i] * B[i];
		}
		System.out.println(answer);
	}
}