#include <iostream>
using namespace std;

struct Matrix {
	long long p[2][2] = { {0, 0}, {0, 0} };
};

Matrix Multiplication(Matrix A, Matrix B) { // 2×2 행렬 A, B의 곱을 리턴하는 함수
	Matrix C;
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

Matrix Power(Matrix A, long long n) { // A의 n제곱을 리턴하는 함수
	Matrix P = A, Q;
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
	cin >> N;
	
	// 행렬A 만들기
	Matrix A;
	A.p[0][0] = 2; A.p[0][1] = 1; A.p[1][0] = 1;
	
	// B=A^{N-1} 계산
	Matrix B = Power(A, N - 1);

	// 답 출력
	cout << (B.p[1][0] + B.p[1][1]) % 1000000007 << endl;
	return 0;
}