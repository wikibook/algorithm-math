#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int N = 100;
int Q = 1000;
int A[109][109], B[109][109];
int X[1009], Y[1009], H[1009];

// L 이상 R 이하의 무작위 정수를 반환하는 함수
int RandInt(int L, int R) {
	return rand() % (R - L + 1) + L;
}

// 현재 점수를 반환하는 함수
int GetScore() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) sum += abs(A[i][j] - B[i][j]);
	}
	return 200000000 - sum;
}

// X[t]=x, Y[t]=y, H[t]=h로 변경하는 함수
void Change(int t, int x, int y, int h) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B[j][i] -= max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
		}
	}
	X[t] = x;
	Y[t] = y;
	H[t] = h;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B[j][i] += max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
		}
	}
}

void Yamanobori() {
	// 변수 설정(5.95초 동안 루프를 돌린다)
	int TIMELIMIT = 5.95 * CLOCKS_PER_SEC;
	int CurrentScore = GetScore();
	int ti = clock();

	// 등산 알고리즘 시작
	while (clock() - ti < TIMELIMIT) {
		int t = RandInt(1, Q);
		int old_x = X[t], new_x = X[t] + RandInt(-9, 9);
		int old_y = Y[t], new_y = Y[t] + RandInt(-9, 9);
		int old_h = H[t], new_h = H[t] + RandInt(-19, 19);
		if (new_x < 0 || new_x >= N) continue;
		if (new_y < 0 || new_y >= N) continue;
		if (new_h <= 0 || new_h > N) continue;

		// 일단 변경하고, 점수를 평가한다
		Change(t, new_x, new_y, new_h);
		int NewScore = GetScore();

		// 점수에 따라 채용 여부를 결정한다
		if (CurrentScore < NewScore) CurrentScore = NewScore;
		else Change(t, old_x, old_y, old_h);
	}
}

int main() {
	// 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}

	// 초기 해 생성
	for (int i = 1; i <= 1000; i++) {
		X[i] = rand() % N; // 0 이상 N-1 이하의 무작위 정수
		Y[i] = rand() % N; // 0 이상 N-1 이하의 무작위 정수
		H[i] = 1;
		B[X[i]][Y[i]] += 1;
	}

	// 등산 알고리즘
	Yamanobori();

	// 출력
	cout << "1000" << endl;
	for (int i = 1; i <= 1000; i++) {
		cout << X[i] << " " << Y[i] << " " << H[i] << endl;
	}
	return 0;
}
