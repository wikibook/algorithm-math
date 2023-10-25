#include <iostream>
using namespace std;
 
int N, T;
int L[500009], R[500009];
int A[500009], B[500009];
 
int main() {
	// 입력
	cin >> T >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];
	
	// 계차 B[i] 계산하기
	for (int i = 0; i <= T; i++) B[i] = 0;
	for (int i = 1; i <= N; i++) {
		B[L[i]] += 1;
		B[R[i]] -= 1;
	}
	
	// 누적합 A[i] 계산하기
	A[0] = B[0];
	for (int i = 1; i <= T; i++) {
		A[i] = A[i - 1] + B[i];
	}
	
	// 답 출력
	for (int i = 0; i < T; i++) cout << A[i] << endl;
	return 0;
}