#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// 입력
	long long N;
	cin >> N;

	// 세로 길이를 1부터 √N까지 전체 탐색
	long long answer = (1LL << 60);
	for (long long x = 1; x * x <= N; x++) {
		if (N % x == 0) {
			answer = min(answer, 2 * x + 2 * (N / x));
		}
	}

	// 답 출력
	cout << answer << endl;

	return 0;
}