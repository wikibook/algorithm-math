#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int N, X[159], Y[159];
int P[159];

// a 이상 b 이하의 정수를 무작위로 반환하는 함수
int RandInt(int a, int b) {
	return a + rand() % (b - a + 1);
}

// 도시 p와 q 사이의 거리를 구하는 함수
double GetDistance(int p, int q) {
	return sqrt((X[p] - X[q]) * (X[p] - X[q]) + (Y[p] - Y[q]) * (Y[p] - Y[q]));
}

// 점수를 계산하는 함수
double GetScore() {
	double sum = 0;
	for (int i = 1; i <= N; i++) sum += GetDistance(P[i], P[i + 1]);
	return sum;
}

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 초기 해 생성
	P[1] = 1; P[N + 1] = 1;
	for (int i = 2; i <= N; i++) P[i] = i;

	// 등산 알고리즘
	double CurrentScore = GetScore();
	for (int t = 1; t <= 200000; t++) {
		// 무작위로 반전시킬 구간 [L, R]를 선택한다
		int L = RandInt(2, N);
		int R = RandInt(2, N);
		if (L > R) swap(L, R);

		// reverse는 배열의 L ~ R번째를 반전시키는 함수
		reverse(P + L, P + R + 1);
		double NewScore = GetScore();

		// 개선되면 점수를 업데이트, 악화되면 원래대로 되돌린다
		if (CurrentScore >= NewScore) CurrentScore = NewScore;
		else reverse(P + L, P + R + 1);
	}

	// 출력
	for (int i = 1; i <= N + 1; i++) cout << P[i] << endl;
	return 0;
}
