#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int N, X[159], Y[159];
int P[159];

// 0 이상 1 이하의 무작위 정수를 반환하는 함수
double Randouble() {
	return 1.0 * rand() / RAND_MAX;
}

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 초기 해 생성
	P[1] = 1; P[N + 1] = 1;
	for (int i = 2; i <= N; i++) P[i] = i;

	// 담금질 알고리즘(GetScore 함수, RandInt 함수는 7.2절을 참조)
	double CurrentScore = GetScore();
	for (int t = 1; t <= 200000; t++) {
		int L = RandInt(2, N);
		int R = RandInt(2, N);
		if (L > R) swap(L, R);
		reverse(P + L, P + R + 1);
		double NewScore = GetScore();

		// 7.2절의 해답 예로부터 변경한 유일한 부분(Probability는 채용 확률)
		double T = 30.00 - 28.00 * t / 200000.0;
		double Probability = exp(min(0.0, (CurrentScore - NewScore) / T));
		if (Randouble() < Probability) CurrentScore = NewScore;
		else reverse(P + L, P + R + 1);
	}

	// 출력
	for (int i = 1; i <= N + 1; i++) cout << P[i] << endl;
	return 0;
}
