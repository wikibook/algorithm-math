#include <iostream>
using namespace std;

int main() {
	// 입력
	int N;
	cin >> N; N -= 1;

	// 출력
	for (int x = 9; x >= 0; x--) {
		int wari = (1 << x);
		if ((N / wari) % 2 == 0) cout << "4"; // 2진법 0이 4에 대응
		if ((N / wari) % 2 == 1) cout << "7"; // 2진법의 1이 7에 대응
	}
	cout << endl;
	return 0;
}
