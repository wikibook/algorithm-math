#include <iostream>
#include <algorithm>
using namespace std;

int N, A[200009];

int main() {
	// 입력(예를 들어  N=5, A[1]=3, A[2]=1, A[3]=4, A[4]=1, A[5]=5를 입력한 경우)
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 정렬(반개구간 [1, N+1)을 정렬하므로, 매개변수에 A+1, A+N+1을 지정합니다).
	// sort 함수로 배열의 내용이 [3,1,4,1,5]에서 [1,1,3,4,5]로 바뀝니다.
	sort(A + 1, A + N + 1);

	// 출력(1, 1, 3, 4, 5 순서로 출력됨)
	for (int i = 1; i <= N; i++) cout << A[i] << endl;
	return 0;
}