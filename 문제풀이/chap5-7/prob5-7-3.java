import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		for (int i = 1; i <= N; i++) {
			A[i - 1] = sc.nextLong();
		}
		
		// 배열A 전체를 정렬
		Arrays.sort(A);
		
		// 답 구하기
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += A[i - 1] * (-N + 2L * i - 1L);
		}
		
		// 출력
		System.out.println(Answer);
	}
}