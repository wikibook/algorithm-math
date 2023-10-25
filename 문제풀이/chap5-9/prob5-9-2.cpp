#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
long long N;
long long A[100009], B[100009];
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	
	// 정렬
	sort(A + 1, A + N + 1);
	sort(B + 1, B + N + 1);
	
	// 답 구하기
	long long Answer = 0;
	for (int i = 1; i <= N; i++) Answer += abs(A[i] - B[i]);
	cout << Answer << endl;
	return 0;
}