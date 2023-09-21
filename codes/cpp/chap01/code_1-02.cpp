#include <iostream>
using namespace std;

int main() {
	// 입력
	int N, K, Answer = 0;
	cin >> N >> K;

	// 완전 탐색
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int z = 1; z <= N; z++) {
				if (x + y + z == K) Answer += 1;
			}
		}
	}

	// 출력
	cout << Answer << endl;
	return 0;
}
