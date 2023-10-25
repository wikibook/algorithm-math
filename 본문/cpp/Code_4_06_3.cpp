#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long a, b, Answer = 1; // a의 0 제곱은 1이므로, Answer=1로 초기화해둡니다.

int main() {
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		Answer = (Answer * a) % mod;
	}
	cout << Answer << endl;
	return 0;
}