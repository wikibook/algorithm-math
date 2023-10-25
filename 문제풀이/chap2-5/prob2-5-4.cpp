#include <iostream>
using namespace std;

bool isprime(int x) {
	for (int i = 2; i <= x - 1; i++) {
		// x를 i로 나눈 나머지가 0이라면, x는 i로 나누어짐
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	// 입력
	int N;
	cin >> N;
	
	// 답 출력(공백 문자로 구분해서 출력하는 경우)
	for (int i = 2; i <= N; i++) {
		if (isprime(i) == true) {
			if (i >= 3) cout << " ";
			cout << i;
		}
	}
	cout << endl;
	return 0;
}