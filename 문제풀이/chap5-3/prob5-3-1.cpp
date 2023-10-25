#include <iostream>
using namespace std;

int main() {
	// 입력
	long long H, W;
	cin >> H >> W;
	
	// 조건 분기
	if (H == 1 || W == 1) {
		cout << "1" << endl;
	}
	else {
		cout << (H * W + 1) / 2 << endl;
	}
	return 0;
}