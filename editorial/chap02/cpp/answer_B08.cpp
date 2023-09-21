#include <iostream>
using namespace std;
 
// 입력으로 주어지는 변수
int N, X[100009], Y[100009];
int Q, A[100009], B[100009], C[100009], D[100009];
 
// 각 좌표에 있는 점의 개수 S[i][j], 2차원 누적 합 T[i][j]
int S[1509][1509];
int T[1509][1509];
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
 
	// 각 좌표에 있는 점의 개수를 계산한다.
	for (int i = 1; i <= N; i++) S[X[i]][Y[i]] += 1;
 
	// 누적 합을 구한다
	for (int i = 0; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++) T[i][j] = 0;
	}
	for (int i = 1; i <= 1500; i++) {
		for (int j = 1; j <= 1500; j++) T[i][j] = T[i][j - 1] + S[i][j];
	}
	for (int i = 1; i <= 1500; i++) {
		for (int j = 1; j <= 1500; j++) T[i][j] = T[i - 1][j] + T[i][j];
	}
 
	// 답을 구한다
	for (int i = 1; i <= Q; i++) {
		cout << T[C[i]][D[i]] + T[A[i] - 1][B[i] - 1] - T[A[i] - 1][D[i]] - T[C[i]][B[i] - 1] << endl;
	}
	return 0;
}
