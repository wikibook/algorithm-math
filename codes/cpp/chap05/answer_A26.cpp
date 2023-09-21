#include <iostream>
using namespace std;

// x가 소수일 때 true, 소수가 아닐 때 false를 반환한다
bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	// 입력
	int Q, X[10009];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> X[i];

	// 출력
	for (int i = 1; i <= Q; i++) {
		bool Answer = isPrime(X[i]);
		if (Answer == true) cout << "Yes" << endl;
		if (Answer == false) cout << "No" << endl;
	}
	return 0;
}
