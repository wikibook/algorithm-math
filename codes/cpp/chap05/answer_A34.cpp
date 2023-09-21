#include <iostream>
using namespace std;

int N, X, Y, A[100009];
int grundy[100009];

int main() {
	// [ 입력 ]
	cin >> N >> X >> Y;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// [ Grundy 수를 구한다 ]
	// 변수 grundy[i]: 돌이 i개일 때의 Grundy 수
	// 변수 Transit[i]: Grundy 수가 i가 되도록 전이할 수 있는가
	for (int i = 0; i <= 100000; i++) {
		bool Transit[3] = { false, false, false };
		if (i >= X) Transit[grundy[i - X]] = true;
		if (i >= Y) Transit[grundy[i - Y]] = true;
		if (Transit[0] == false) grundy[i] = 0;
		else if (Transit[1] == false) grundy[i] = 1;
		else grundy[i] = 2;
	}

	// [ 출력 ]
	int XOR_Sum = 0;
	for (int i = 1; i <= N; i++) XOR_Sum = (XOR_Sum ^ grundy[A[i]]);
	if (XOR_Sum != 0) cout << "First" << endl;
	if (XOR_Sum == 0) cout << "Second" << endl;
	return 0;
}
