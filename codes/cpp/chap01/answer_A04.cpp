#include <iostream>
using namespace std;

int main() {
	// 입력
	int N;
	cin >> N;

	// 윗자리부터 순서대로 '2진법으로 변환한 값'을 구한다
	for (int x = 9; x >= 0; x--) {
		int wari = (1 << x); // 2의 x제곱
		cout << (N / wari) % 2; // 나눗셈의 결과에 따라 0 또는 1을 출력
	}
	cout << endl; // 마지막에 줄바꿈한다
	return 0;
}
