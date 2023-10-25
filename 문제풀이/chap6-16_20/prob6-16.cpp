#include <iostream>
using namespace std;

int main() {
	// 입력
	int N, X;
	cin >> N >> X;

	// 모든 (a, b, c) 조합 확인하기
	int answer = 0;
	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			for (int c = b + 1; c <= N; c++) {
				if (a + b + c == X) {
					answer += 1;
				}
			}
		}
	}

	// 답 출력
	cout << answer << endl;

	return 0;
}