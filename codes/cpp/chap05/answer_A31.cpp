#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	long long A1 = (N / 3); // 3으로 나누어떨어지는 수의 개수
	long long A2 = (N / 5); // 5로 나누어떨어지는 수의 개수
	long long A3 = (N / 15); // 3, 5 모두로 나누어떨어지는 수(= 15의 배수)의 개수
	cout << A1 + A2 - A3 << endl;
	return 0;
}
