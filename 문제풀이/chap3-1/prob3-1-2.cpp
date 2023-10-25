#include <iostream>
using namespace std;

int main() {
	// 입력
	long long N;
	cin >> N;
	
	// 소인수분해(공백으로 구분해서 출력)
	bool flag = false;
	for (long long i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			if (flag == true) cout << " ";
			flag = true;
			N /= i;
			cout << i;
		}
	}
	if (N >= 2) {
		if (flag == true) cout << " ";
		flag = true;
		cout << N;
	}
	cout << endl;
	return 0;
}