#include <iostream>
using namespace std;

int main() {
	// 입력 부분
	int a, b;
	cin >> a >> b;

	// 출력 부분
	cout << (a & b) << endl; // a AND b 의 값을 출력
	cout << (a | b) << endl; // a OR b 의 값을 출력
	cout << (a ^ b) << endl; // a XOR b 의 값을 출력
	return 0;
}
