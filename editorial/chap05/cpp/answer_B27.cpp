#include <iostream>
using namespace std;

int GCD(int A, int B) {
	while (A >= 1 && B >= 1) {
		if (A >= B) {
			A = (A % B); // A의 값을 변경하는 경우
		}
		else {
			B = (B % A); // B의 값을 변경하는 경우
		}
	}
	if (A != 0) return A;
	return B;
}

int main() {
	long long A, B;
	cin >> A >> B;
	cout << A * B / GCD(A, B) << endl;
	return 0;
}
