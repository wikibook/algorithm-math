#include <iostream>
#include <algorithm>
using namespace std;

int N, A[69], B[69];
int Answer = 0;

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];

	// 배열 정렬(reverse 함수는 배열을 역순으로 하는 함수)
	sort(A + 1, A + N + 1);
	sort(B + 1, B + N + 1); reverse(B + 1, B + N + 1);

	// 답을 구한다
	for (int i = 1; i <= N; i++) Answer += A[i] * B[i];
	cout << Answer << endl;
	return 0;
}
