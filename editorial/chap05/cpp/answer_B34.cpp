#include <iostream>
using namespace std;

long long N, X, Y, A[100009];

int main() {
	// 입력
	cin >> N >> X >> Y;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// Grundy 수 계산
	int XOR_Sum = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] % 5 == 0 || A[i] % 5 == 1) XOR_Sum ^= 0;
		if (A[i] % 5 == 2 || A[i] % 5 == 3) XOR_Sum ^= 1;
		if (A[i] % 5 == 4) XOR_Sum ^= 2;
	}

	// 출력
	if (XOR_Sum != 0) cout << "First" << endl;
	if (XOR_Sum == 0) cout << "Second" << endl;
	return 0;
}
