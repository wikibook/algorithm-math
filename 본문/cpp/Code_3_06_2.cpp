#include <iostream>
using namespace std;

int N, A[200009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 선택 정렬
	for (int i = 1; i <= N - 1; i++) {
		int Min = i, Min_Value = A[i];
		for (int j = i + 1; j <= N; j++) {
			if (A[j] < Min_Value) {
				Min = j; // Min은 최솟값의 인덱스(1～N)
				Min_Value = A[j]; // min_value는 현재 시점에서 최소값
			}
		}
		swap(A[i], A[Min]);
	}

	// 출력
	for (int i = 1; i <= N; i++) cout << A[i] << endl;
	return 0;
}