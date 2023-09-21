#include <iostream>
using namespace std;

int main() {
	// 입력
	int N, A[200009]; long long Answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 완전 탐색(선택하는 막대의 번호를 오름차순으로 i, j, k라 한다)
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (A[i] == A[j] && A[j] == A[k]) Answer += 1;
			}
		}
	}
	cout << Answer << endl;
	return 0;
}
