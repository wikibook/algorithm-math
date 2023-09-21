#include <iostream>
#include <algorithm>
using namespace std;

int N, A[109];
int Answer = 0;

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 답을 구한다（완전 탐색）
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) Answer = max(Answer, A[i] + A[j]);
	}

	// 출력
	cout << Answer << endl;
	return 0;
}
