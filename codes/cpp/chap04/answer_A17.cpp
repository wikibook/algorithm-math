#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N, A[100009], B[100009], dp[100009];
vector<int> Answer;

int main() {
	// 입력
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> A[i];
	for (int i = 3; i <= N; i++) cin >> B[i];

	// 동적 계획 알고리즘
	dp[1] = 0;
	dp[2] = A[2];
	for (int i = 3; i <= N; i++) dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);

	// 답의 복원
	// 변수 Place는 현재 위치(목표부터 진행한다)
	// 예를 들어, 입력 예의 경우 Place는 5 → 4 → 2 → 1로 변화한다
	int Place = N;
	while (true) {
		Answer.push_back(Place);
		if (Place == 1) break;

		// 어디에서 방 Place로 이동하는 것이 최적인지 구한다
		if (dp[Place - 1] + A[Place] == dp[Place]) Place = Place - 1;
		else Place = Place - 2;
	}

	// 변수 Answer는 '목표부터의 경로'이므로 역순으로 한다
	// 예를 들어, 입력 예의 경우, Answer = {5, 4, 2, 1}을 {1, 2, 4, 5}로 한다
	reverse(Answer.begin(), Answer.end());

	// 답을 출력
	cout << Answer.size() << endl;
	for (int i = 0; i < Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
