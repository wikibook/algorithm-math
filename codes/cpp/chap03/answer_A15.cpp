#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 입력
	int N, A[100009], B[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 배열 T 작성
	vector<int> T;
	for (int i = 1; i <= N; i++) T.push_back(A[i]);
	sort(T.begin(), T.end());

	// 배열 T의 중복을 제거한다
	// erase 함수, unique 함수는 이 책의 범위를 벗어나지만, 꼭 확인해 두자
	T.erase(unique(T.begin(), T.end()), T.end());

	// 답을 구한다
	for (int i = 1; i <= N; i++) {
		// vector 타입의 lower_bound는 다음과 같은 형식으로 작성한다
		// vector 타입의 첨자는 0번부터 시작하므로 1을 더해야 하는 점에 주의한다
		B[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
		B[i] += 1;
	}

	// 답을 공백으로 구분해서 출력
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << B[i];
	}
	cout << endl;
	return 0;
}
