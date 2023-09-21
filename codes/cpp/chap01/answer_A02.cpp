#include <iostream>
using namespace std;

int N, X, A[109];
bool Answer = false;

int main() {
	// 입력
	cin >> N >> X;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 완전 탐색(변수 Answer는 '기존에 x를 발견했는가'를 나타냄)
	for (int i = 1; i <= N; i++) {
		if (A[i] == X) Answer = true;
	}

	// 출력
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
