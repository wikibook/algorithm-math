#include <stdio.h>
#include <stdbool.h>

const long long MOD = 1000000000;

typedef struct {
	long long p[2][2];
} matrix;

// 모든 요소가 0인 2×2 행렬(= [[0, 0], [0, 0]])을 리턴하는 함수
matrix zero_matrix() {
	matrix A;
	A.p[0][0] = 0; A.p[0][1] = 0;
	A.p[1][0] = 0; A.p[1][1] = 0;
	return A;
}

// 2×2 행렬 곱을 리턴하는 함수
matrix multiplication(matrix A, matrix B) {
	matrix C = zero_matrix();
	int i, j, k;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= MOD;
			}
		}
	}
	return C;
}

// 행렬 A의 n제곱을 리턴하는 함수
matrix power(matrix A, long long n) {
	matrix P = A;
	matrix Q = zero_matrix();
	bool flag = false;
	for (int i = 0; i < 60; i++) {
		if ((n & (1LL << i)) != 0LL) {
			if (flag == false) {
				Q = P;
				flag = true;
			}
			else {
				Q = multiplication(Q, P);
			}
		}
		P = multiplication(P, P);
	}
	return Q;
}

int main() {
	// 입력 → 거듭 제곱 계산(N이 2 이상이 아니라면 제대로 작동하지 않으므로 주의)
	long long N;
	scanf("%lld", &N);
	matrix A; A.p[0][0] = 1; A.p[0][1] = 1; A.p[1][0] = 1; A.p[1][1] = 0;
	matrix B = power(A, N - 1);
	
	// 출력(아래에서 9번째 자리가 0이라면, 앞에 0을 포함하지 않는 형태로 출력되므로 주의해주세요).
	printf("%lld\n", (B.p[1][0] + B.p[1][1]) % MOD);
	
	return 0;
}
