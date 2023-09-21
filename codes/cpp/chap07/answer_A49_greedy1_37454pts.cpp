// ###############################################
// # 책 XXX페이지 전반부의 탐욕 알고리즘을 이용한 구현입니다.
// ###############################################

#include <iostream>
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
	int CurrentScore = 0;
	for (int i = 1; i <= T; i++) {
		// 패턴 A일 때의 점수 구하기
		int ScoreA = CurrentScore;
		for (int j = 1; j <= 20; j++) PatA[j] = A[j];
		PatA[P[i]] += 1;
		PatA[Q[i]] += 1;
		PatA[R[i]] += 1;
		for (int j = 1; j <= 20; j++) {
			if (PatA[j] == 0) ScoreA += 1;
		}

		// 패턴 B일 때의 점수 구하기
		int ScoreB = CurrentScore;
		for (int j = 1; j <= 20; j++) PatB[j] = A[j];
		PatB[P[i]] -= 1;
		PatB[Q[i]] -= 1;
		PatB[R[i]] -= 1;
		for (int j = 1; j <= 20; j++) {
			if (PatB[j] == 0) ScoreB += 1;
		}

		// 점수가 높은 쪽을 채택
		if (ScoreA >= ScoreB) {
			cout << "A" << endl;
			CurrentScore = ScoreA;
			for (int j = 1; j <= 20; j++) A[j] = PatA[j];
		}
		else {
			cout << "B" << endl;
			CurrentScore = ScoreB;
			for (int j = 1; j <= 20; j++) A[j] = PatB[j];
		}
	}
	return 0;
}
