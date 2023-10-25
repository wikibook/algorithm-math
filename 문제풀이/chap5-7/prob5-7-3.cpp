#include <iostream>
#include <algorithm>
using namespace std;
 
long long N, A[200009];
long long Answer = 0;
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 정렬(코드 5.7.1에서 추가한 유일한 부분)
	sort(A + 1, A + N + 1);
	
	// 답 구하기 → 답 출력
	for (int i = 1; i <= N; i++) Answer += A[i] * (-N + 2LL * i - 1LL);
	cout << Answer << endl;
	return 0;
}