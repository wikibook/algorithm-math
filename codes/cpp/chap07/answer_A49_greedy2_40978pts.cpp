// ###############################################
// # 책 XXX페이지 후반부의 평가 함수를 이용한 구현입니다.
// ###############################################

#include <iostream>
#include <cmath>
using namespace std;

int T, P[109], Q[109], R[109];
int A[109];
int PatA[109], PatB[109];

int main() {
	// 입력
	cin >> T;
	for (int i = 1; i <= T; i++) cin >> P[i] >> Q[i] >> R[i];

	// 배열 A 초기화
	for (int i = 1; i <= 20; i++) A[i] = 0;

	// 탐욕 알고리즘
	for (int i = 1; i <= T; i++) {
		// 패턴 A일 때의 점수 구하기
		int ScoreA = 0;
		for (int j = 1; j <= 20; j++) PatA[j] = A[j];
		PatA[P[i]] += 1;
		PatA[Q[i]] += 1;
		PatA[R[i]] += 1;
		for (int j = 1; j <= 20; j++) ScoreA += abs(PatA[j]);

		// 패턴 B일 때의 점수 구하기
		int ScoreB = 0;
		for (int j = 1; j <= 20; j++) PatB[j] = A[j];
		PatB[P[i]] -= 1;
		PatB[Q[i]] -= 1;
		PatB[R[i]] -= 1;
		for (int j = 1; j <= 20; j++)  ScoreB += abs(PatB[j]);

		// 점수가 낮은 쪽을 채택
		if (ScoreA <= ScoreB) {
			cout << "A" << endl;
			for (int j = 1; j <= 20; j++) A[j] = PatA[j];
		}
		else {
			cout << "B" << endl;
			for (int j = 1; j <= 20; j++) A[j] = PatB[j];
		}
	}
	return 0;
}
