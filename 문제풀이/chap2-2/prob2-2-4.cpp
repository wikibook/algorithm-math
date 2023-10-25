#include <iostream>
using namespace std;

int N, A[109];
int Answer = 0;

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	// 답 계산
	for (int i = 1; i <= N; i++) {
		Answer += A[i];
	}

	// 출력
	cout << Answer % 100 << endl;
	return 0;
}
