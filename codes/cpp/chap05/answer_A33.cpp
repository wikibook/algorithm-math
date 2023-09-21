#include <iostream>
using namespace std;

int N, A[100009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 전부 XOR한 값(Nim sum)을 구한다
	int XOR_Sum = A[1];
	for (int i = 2; i <= N; i++) XOR_Sum = (XOR_Sum ^ A[i]);

	// 출력
	if (XOR_Sum != 0) cout << "First" << endl;
	if (XOR_Sum == 0) cout << "Second" << endl;
	return 0;
}
