import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] X = new long[N];
		long[] Y = new long[N];
		for (int i = 1; i <= N; i++) {
			X[i - 1] = sc.nextLong();
			Y[i - 1] = sc.nextLong();
		}
		
		// 배열 X, Y 정렬하기
		Arrays.sort(X);
		Arrays.sort(Y);
		
		// Part1의 답(x 좌표 차의 절댓값 총합)
		long Part1 = 0;
		for (int i = 1; i <= N; i++) Part1 += X[i - 1] * (-N + 2L * i - 1L);
		
		// Part2의 답(y 좌표 차의 절댓값 총합)
		long Part2 = 0;
		for (int i = 1; i <= N; i++) Part2 += Y[i - 1] * (-N + 2L * i - 1L);
		
		// 출력
		System.out.println(Part1 + Part2);
	}
}