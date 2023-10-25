#include <iostream>
#include <algorithm>
using namespace std;

int N, B[109];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> B[i];
	}

	// 수열A의 요소 합계 구하고 출력하기
	int answer = B[1] + B[N - 1];
	for (int i = 2; i <= N - 1; i++) {
		answer += min(B[i - 1], B[i]);
	}
	cout << answer << endl;

	return 0;
}