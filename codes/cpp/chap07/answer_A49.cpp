#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 상태를 나타내는 구조체
struct State {
	int score; // 잠정 점수
	int X[29]; // 현재 배열 X의 값
	char LastMove; // 마지막 동작('A' 또는 'B'）
	int LastPos; //Beam[i-1][ 어디 ]에서 전이했는가
};

// sort 함수의 순서를 결정한다(점수가 높은 쪽이 '크다'고 한다)
bool operator>(const State& a1, const State& a2) {
	if (a1.score > a2.score) return true;
	else return false;
}

// 필요한 변수/배열(WIDTH는 빔 폭,, NumState[i]는 i번째 수 시점에서의 상태 수)
const int WIDTH = 10000;
const int N = 20;
int T, P[109], Q[109], R[109];
int NumState[109];
State Beam[109][WIDTH];
char Answer[109];

// 빔 서치를 수행하는 함수
void BeamSearch() {
	// 0번째 수의 상태를 설정
	NumState[0] = 1;
	Beam[0][0].score = 0;
	for (int i = 1; i <= N; i++) Beam[0][0].X[i] = 0;

	// 빔 서치
	for (int i = 1; i <= T; i++) {
		vector<State> Candidate;
		for (int j = 0; j < NumState[i - 1]; j++) {
			// 조작 A인 경우
			State SousaA = Beam[i - 1][j];
			SousaA.LastMove = 'A';
			SousaA.LastPos = j;
			SousaA.X[P[i]] += 1;
			SousaA.X[Q[i]] += 1;
			SousaA.X[R[i]] += 1;
			for (int k = 1; k <= N; k++) {
				if (SousaA.X[k] == 0) SousaA.score += 1;
			}

			// 조작 B인 경우
			State SousaB = Beam[i - 1][j];
			SousaB.LastMove = 'B';
			SousaB.LastPos = j;
			SousaB.X[P[i]] -= 1;
			SousaB.X[Q[i]] -= 1;
			SousaB.X[R[i]] -= 1;
			for (int k = 1; k <= N; k++) {
				if (SousaB.X[k] == 0) SousaB.score += 1;
			}

			// 후보에 추가
			Candidate.push_back(SousaA);
			Candidate.push_back(SousaB);
		}

		// 정렬해서 Beam[i]의 결과를 계산한다
		sort(Candidate.begin(), Candidate.end(), greater<State>());
		NumState[i] = min(WIDTH, (int)Candidate.size());
		for (int j = 0; j < NumState[i]; j++) Beam[i][j] = Candidate[j];
	}
}

int main() {
	// 입력
	cin >> T;
	for (int i = 1; i <= T; i++) cin >> P[i] >> Q[i] >> R[i];

	// 빔 서치
	BeamSearch();

	// 빔 서치 복원(CurrentPlace는 배열 Beam의 어느 위치를 보고 있는가를 나타낸다)
	int CurrentPlace = 0;
	for (int i = T; i >= 1; i--) {
		Answer[i] = Beam[i][CurrentPlace].LastMove;
		CurrentPlace = Beam[i][CurrentPlace].LastPos;
	}

	// 출력
	for (int i = 1; i <= T; i++) cout << Answer[i] << endl;
	return 0;
}
