#include <iostream>
using namespace std;

long long N, X, Y;

int main() {
	// 입력
	cin >> N >> X >> Y;

	// 4개의 정수 (a, b, c, d)를 전체 탐색 → 답 출력
	for (int a = 1; a <= N; a++) {
		for (int b = a; b <= N; b++) {
			for (int c = b; c <= N; c++) {
				for (int d = c; d <= N; d++) {
					if (a + b + c + d == X && 1LL * a * b * c * d == Y) {
						cout << "Yes" << endl;
						return 0; // 프로그램 실행을 종료합니다.
					}
				}
			}
		}
	}
	cout << "No" << endl; // 하나도 찾지 못했다면 No를 출력
	return 0;
}