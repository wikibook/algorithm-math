#include <iostream>
using namespace std;
 
// 입력으로 주어지는 변수
int N;
int A[100009], B[100009], C[100009], D[100009];
 
// 좌표 (i+0.5, j+0.5)에 놓여 있는 종이의 개수 T[i][j]
int T[1509][1509];
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
 
	// 각 종이에 대해 +1/-1을 더한다.
	for (int i = 0; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++) T[i][j] = 0;
	}
	for (int i = 1; i <= N; i++) {
		T[A[i]][B[i]] += 1;
		T[A[i]][D[i]] -= 1;
		T[C[i]][B[i]] -= 1;
		T[C[i]][D[i]] += 1;
	}
 
	// 2차원 누적 합을 구한다
	for (int i = 0; i <= 1500; i++) {
		for (int j = 1; j <= 1500; j++) T[i][j] = T[i][j - 1] + T[i][j];
	}
	for (int i = 1; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++) T[i][j] = T[i - 1][j] + T[i][j];
	}
 
	// 면적 계산하기
	int Answer = 0;
	for (int i = 0; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++) {
			if (T[i][j] >= 1) Answer += 1;
		}
	}
	cout << Answer << endl;
	return 0;
}
