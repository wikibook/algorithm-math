import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력 → 거듭 제곱 계산(N이 2 이상이 아니라면 제대로 작동하지 않으므로 주의)
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long[][] A = new long[3][3];
		A[0][0] = 1; A[0][1] = 1; A[0][2] = 1;
		A[1][0] = 1; A[1][1] = 0; A[1][2] = 0;
		A[2][0] = 0; A[2][1] = 1; A[2][2] = 0;
		long[][] B = copyMatrix(power(A, N - 1));
		
		// 답 계산 → 출력(아래에서 9번째 자리가 0이라면, 앞에 0을 포함하지 않는 형태로 출력하므로 주의)
		long answer = (2 * B[2][0] + B[2][1] + B[2][2]) % MOD;
		System.out.println(answer);
	}
	static final int MOD = 1000000007;
	static long[][] copyMatrix(long[][] A) {
		// 행렬 복사(단순하게 "M = A;"로 복사하면, 참조 복사되므로 주의)
		long[][] M = new long[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static long[][] multiplication(long[][] A, long[][] B) {
		// 2×2 행렬 A, B의 곱을 리턴하는 함수
		long[][] C = new long[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
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
		long[][] Q = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
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