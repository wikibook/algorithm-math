#include <iostream>
using namespace std;

int main() {
	// 입력
	int N; char S[200009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];

	// 답을 구한다
	bool Answer = false;
	for (int i = 1; i <= N - 2; i++) {
		if (S[i] == 'R' && S[i + 1] == 'R' && S[i + 2] == 'R') Answer = true;
		if (S[i] == 'B' && S[i + 1] == 'B' && S[i + 2] == 'B') Answer = true;
	}

	// 출력
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
