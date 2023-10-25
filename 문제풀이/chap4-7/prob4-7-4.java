import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long K = sc.nextLong();
		long N = sc.nextLong();
		
		// 행렬A 만들기
		long[][] A = new long[(1 << K)][(1 << K)];
		for (int i = 0; i < (1 << K); i++) {
			for (int j = 0; j < (1 << K); j++) {
				if (K == 2) A[i][j] = Mat2[i][j];
				if (K == 3) A[i][j] = Mat3[i][j];
				if (K == 4) A[i][j] = Mat4[i][j];
			}
		}
		
		// B = A^N를 계산하기
		long[][] B = copyMatrix(power(A, N, (1 << K)), (1 << K));
		
		// 답 출력
		System.out.println(B[(1 << K) - 1][(1 << K) - 1]);
	}
	static final int MOD = 1000000007;
	static final long[][] Mat2 = {
		{0, 0, 0, 1},
		{0, 0, 1, 0},
		{0, 1, 0, 0},
		{1, 0, 0, 1}
	};
	static final long[][] Mat3 = {
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0}
	};
	static final long[][] Mat4 = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1}
	};
	static long[][] copyMatrix(long[][] A, int size_) {
		// 행렬 복사(단순하게 "M = A;"로 복사하면, 참조 복사되므로 주의)
		long[][] M = new long[size_][size_];
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static long[][] multiplication(long[][] A, long[][] B, int size_) {
		// 2×2 행렬 A, B의 곱을 리턴하는 함수
		long[][] C = new long[size_][size_];
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				for (int k = 0; k < size_; k++) {
					C[i][j] += A[i][k] * B[k][j];
					C[i][j] %= MOD;
				}
			}
		}
		return C;
	}
	static long[][] power(long[][] A, long n, int size_) {
		// A의 n제곱을 리턴하는 함수
		long[][] P = copyMatrix(A, size_);
		long[][] Q = new long[size_][size_];
		boolean flag = false;
		for (int i = 0; i < 60; i++) {
			if ((n & (1L << i)) != 0L) {
				if (flag == false) {
					Q = copyMatrix(P, size_);
					flag = true;
				}
				else {
					Q = copyMatrix(multiplication(Q, P, size_), size_);
				}
			}
			P = copyMatrix(multiplication(P, P, size_), size_);
		}
		return Q;
	}
}