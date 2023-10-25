import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		int K = sc.nextInt();
		long[] V = new long[K + 1];
		for (int i = 1; i <= K; i++) {
			V[i] = sc.nextLong();
		}
		
		// 비트 전체 탐색
		long Answer = 0;
		for (int i = 1; i < (1 << K); i++) {
			int cnt = 0; // 선택된 숫자의 개수
			long lcm = 1; // 최소공배수
			for (int j = 0; j < K; j++) {
				if ((i & (1 << j)) != 0) {
					cnt += 1;
					lcm = LCM(lcm, V[j + 1]);
				}
			}
			long num = N / lcm; // 선택된 숫자 모두의 배수인 것의 개수
			if (cnt % 2 == 1) Answer += num;
			if (cnt % 2 == 0) Answer -= num;
		}
		
		// 출력
		System.out.println(Answer);
	}
	static long GCD(long A, long B) {
		// 최대공약수를 리턴하는 함수
		if (B == 0) return A;
		return GCD(B, A % B);
	}
	static long LCM(long A, long B) {
		// 최소공배수를 리턴하는 함수
		return (A / GCD(A, B)) * B;
	}
}