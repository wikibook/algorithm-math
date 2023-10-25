import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 입력
		int N = sc.nextInt();
		long[] A = new long[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextLong();
		
		// 답 구하기
		long R = LCM(A[1], A[2]);
		for (int i = 3; i <= N; i++) {
			R = LCM(R, A[i]);
		}
		
		// 출력
		System.out.println(R);
	}
	static long GCD(long A, long B) {
		// 최대공약수를 리턴하는 함수
		while (A >= 1 && B >= 1) {
			if (A < B) {
				B %= A;
			}
			else {
				A %= B;
			}
		}
		if (A >= 1) {
			return A;
		}
		return B;
	}
	static long LCM(long A, long B) {
		// 최소공배수를 리턴하는 함수
		return (A / GCD(A, B)) * B;
	}
}