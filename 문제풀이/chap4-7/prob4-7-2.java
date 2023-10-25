import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력 → 거듭 제곱 계산(N이 2 이상이 아니라면 제대로 작동하지 않으므로 주의)
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long[][] A = new long[2][2];
		A[0][0] = 2; A[0][1] = 1;
		A[1][0] = 1; A[1][1] = 0;
		long[][] B = copyMatrix(power(A, N - 1));
		
		// 답 계산 → 출력(아래에서 9번째 자리가 0이라면, 앞에 0을 포함하지 않는 형태로 출력하므로 주의)
		long answer = (B[1][0] + B[1][1]) % MOD;
		System.out.println(answer);
	}
	static final int MOD = 1000000007;
	static long[][] copyMatrix(long[][] A) {
		// 행렬 복사(단순하게 "M = A;"로 복사하면, 참조 복사되므로 주의)
		long[][] M = new long[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static long[][] multiplication(long[][] A, long[][] B) {
		// 2×2 행렬 A, B의 곱을 리턴하는 함수
		long[][] C = new long[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					C[i][j] += A[i][k] * B[k][j];
					C[i][j] %= MOD;
				}
			}
		}
		return C;
	}
	static long[][] power(long[][] A, long n) {
		// A의 n제곱을 리턴하는 함수
		long[][] P = copyMatrix(A);
		long[][] Q = { { 0, 0 }, { 0, 0 } };
		boolean flag = false;
		for (int i = 0; i < 60; i++) {
			if ((n & (1L << i)) != 0L) {
				if (flag == false) {
					Q = copyMatrix(P);
					flag = true;
				}
				else {
					Q = copyMatrix(multiplication(Q, P));
				}
			}
			P = copyMatrix(multiplication(P, P));
		}
		return Q;
	}
}