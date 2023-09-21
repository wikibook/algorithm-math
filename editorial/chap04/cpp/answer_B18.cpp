#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N, S, A[69];
bool dp[69][10009];
vector<int> Answer;
 
int main() {
	// 입력
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 동적 계획 알고리즘 (i = 0)
	dp[0][0] = true;
	for (int i = 1; i <= S; i++) dp[0][i] = false;
 
	// 동적 계획 알고리즘 (i >= 1)
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			if (j < A[i]) {
				if (dp[i - 1][j] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
			if (j >= A[i]) {
				if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}
 
	// 선택이 존재하지 않는 경우
	if (dp[N][S] == false) {
		cout << "-1" << endl;
		return 0;
	}
 
	// 답의 복원(Place는 '현재 총합')
	int Place = S;
	for (int i = N; i >= 1; i--) {
		if (dp[i - 1][Place] == true) {
			Place = Place - 0; // 카드 i를 선택하지 않음
		}
		else {
			Place = Place - A[i]; // 카드 i 선택
			Answer.push_back(i);
		}
	}
	reverse(Answer.begin(), Answer.end());
 
	// 출력
	cout << Answer.size() << endl;
	for (int i = 0; i < Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
