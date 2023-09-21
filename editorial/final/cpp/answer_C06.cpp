#include <iostream>
using namespace std;

int main() {
	// 입력
	int N;
	cin >> N;

	// 출력
	cout << N << endl;
	for (int i = 1; i <= N; i++) {
		cout << i << " " << i % N + 1 << endl;
	}
	return 0;
}
