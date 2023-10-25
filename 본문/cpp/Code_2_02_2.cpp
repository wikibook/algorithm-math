#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b; // a와 b를 입력
	cout << (a & b) << endl; // a AND b의 값을 출력
	cout << (a | b) << endl; // a OR b의 값을 출력
	cout << (a ^ b) << endl; // a XOR b의 값을 출력
	return 0;
}