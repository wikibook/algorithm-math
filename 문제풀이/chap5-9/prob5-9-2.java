import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		long[] B = new long[N];
		for (int i = 1; i <= N; i++) A[i - 1] = sc.nextLong();
		for (int i = 1; i <= N; i++) B[i - 1] = sc.nextLong();
		
		// 배열 A, B 정렬하기
		Arrays.sort(A);
		Arrays.sort(B);
		
		// 답 구하기
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += Math.abs(A[i - 1] - B[i - 1]);
		}
		
		// 출력
		System.out.println(Answer);
	}
}