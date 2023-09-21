#include <iostream>
using namespace std;

int N, K;
int A[100009], R[100009];

int main() {
	// 입력
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 자벌레 알고리즘
	for (int i = 1; i <= N - 1; i++) {
		// 시작 지점을 결정한다
		if (i == 1) R[i] = 1;
		else R[i] = R[i - 1];

		// 한계까지 더해간다
		while (R[i] < N && A[R[i] + 1] - A[i] <= K) {
			R[i] += 1;
		}
	}

	// 출력(답은 최대 50억 정도가 되므로 long long 타입을 사용해야 한다)
	long long Answer = 0;
	for (int i = 1; i <= N - 1; i++) Answer += (R[i] - i);
	cout << Answer << endl;
	return 0;
}
