#include <iostream>
#include <algorithm>
using namespace std;

long long N, X, A[1000009];

int main() {
	// 입력
	cin >> N >> X;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 배열 정렬
	sort(A + 1, A + N + 1);

	// 이진탐색
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2; // 탐색 범위 중앙으로 분할하기
		if (A[mid] == X) { cout << "Yes" << endl; return 0; }
		if (A[mid] > X) right = mid - 1; // 탐색 범위를 앞부분으로 변경
		if (A[mid] < X) left = mid + 1; // 탐색 범위를 뒷부분으로 변경
	}

	// 더 이상 탐색할 것이 없는 경우도 No를 출력
	cout << "No" << endl;
	return 0;
}