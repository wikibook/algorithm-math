#include <iostream>
using namespace std;

int main() {
	// 입력
	int N, X, Y;
	cin >> N >> X >> Y;

	// 답 구하기
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i % X == 0 || i % Y == 0) cnt++; // mod 계산은 2.2절 참고
	}

	// 출력
	cout << cnt << endl;
	return 0;
}