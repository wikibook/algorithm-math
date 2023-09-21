#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;

	long long A1 = (N /   3); // 3으로 나누어떨어지는 수의 개수
	long long A2 = (N /   5); // 5로 나누어떨어지는 수의 개수
	long long A3 = (N /   7); // 5로 나누어떨어지는 수의 개수
	long long A4 = (N /  15); // 3, 5로 나누어떨어지는 수(= 15의 배수)의 개수
	long long A5 = (N /  21); // 3, 7로 나누어떨어지는 수(= 21의 배수)의 개수
	long long A6 = (N /  35); // 5, 7로 나누어떨어지는 수(= 35의 배수)의 개수
	long long A7 = (N / 105); // 3, 5, 7로 나누어떨어지는 수(= 105의 배수)의 개수
	cout << A1 + A2 + A3 - A4 - A5 - A6 + A7 << endl;
	return 0;
}
