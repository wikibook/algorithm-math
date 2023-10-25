#include <stdio.h>
#include <stdbool.h>

struct Matrix {
	long long p[2][2];
};

// 2×2 행렬 A, B의 곱을 리턴하는 함수
struct Matrix Multiplication(struct Matrix A, struct Matrix B) { 
	struct Matrix C;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) C.p[i][j] = 0;
	}
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < 2; j++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= 1000000007;
			}
		}
	}
	return C;
}

// A의 n제곱을 리턴하는 함수
struct Matrix Power(struct Matrix A, long long n) { 
	struct Matrix P = A, Q;
	bool flag = false;
	for (int i = 0; i < 60; i++) {
		if ((n & (1LL << i)) != 0LL) {
			if (flag == false) { Q = P; flag = true; }
			else { Q = Multiplication(Q, P); }
		}
		P = Multiplication(P, P);
	}
	return Q;
}

int main() {
	// 입력 → 거듭 제곱 계산(N이 2 이상이 아니라면 제대로 작동하지 않으므로 주의)
	long long N;
	scanf("%lld", &N);
	
	// 행렬A 만들기
	struct Matrix A;
	A.p[0][0] = 2; A.p[0][1] = 1;
	A.p[1][0] = 1; A.p[1][1] = 0;
	
	// B=A^{N-1} 계산
	struct Matrix B = Power(A, N - 1);

	// 답 출력
	printf("%lld\n", (B.p[1][0] + B.p[1][1]) % 1000000007);
	return 0;
}