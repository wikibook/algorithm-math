#include <iostream>
using namespace std;

int A, B, Answer = 0;

// 작은 문제 t를 푸는 함수
bool shou_mondai(int t) {
	int cl = (A + t - 1) / t; // A÷t의 소수점 아래를 자릅니다.
	int cr = B / t; // B÷t의 소수점 아래를 자릅니다.
	if (cr - cl >= 1) return true;
	return false;
}

int main() {
	cin >> A >> B;
	for (int i = 1; i <= B; i++) {
		if (shou_mondai(i) == true) Answer = i;
	}
	cout << Answer << endl;
	return 0;
}