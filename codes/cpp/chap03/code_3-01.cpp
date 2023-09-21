#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// 입력
	int N, A[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 배열 정렬
	// 여기에서 함수 sort(A+L, A+R)에서는 A[L]부터 A[R-1]까지의 부분을 정렬한다
	sort(A + 1, A + N + 1);

	// 출력
	for (int i = 1; i <= N; i++) cout << A[i] << endl;
	return 0;
}
