#include <iostream>
using namespace std;

int H, W;
int N, A[200009], B[200009];

int main() {
	// 입력
	cin >> N >> H >> W;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

	// 전부 XOR한 값(Nim sum)을 구한다
	int XOR_Sum = 0;
	for (int i = 1; i <= N; i++) XOR_Sum = (XOR_Sum ^ (A[i] - 1));
	for (int i = 1; i <= N; i++) XOR_Sum = (XOR_Sum ^ (B[i] - 1));

	// 출력
	if (XOR_Sum != 0) cout << "First" << endl;
	if (XOR_Sum == 0) cout << "Second" << endl;
	return 0;
}
