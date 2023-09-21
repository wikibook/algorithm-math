#include <iostream>
using namespace std;
 
long long N, K;
long long A[100009];
long long S[100009]; // 누적 합계
long long R[100009]; // 왼쪽 끝이 정해지면 오른쪽 끝은 어디까지 갈 수 있을까
 
// A[l]에서 A[r]까지의 합계값
long long sum(int l, int r) {
	return S[r] - S[l - 1];
}
 
int main() {
	// 입력
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 누적 합을 구한다
	S[0] = 0;
	for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
 
	// 자벌레 알고리즘
	for (int i = 1; i <= N; i++) {
		if (i == 1) R[i] = 0;
		else R[i] = R[i - 1];
		while (R[i] < N && sum(i, R[i] + 1) <= K) {
			R[i] += 1;
		}
	}
	
	// 답을 구한다
	long long Answer = 0;
	for (int i = 1; i <= N; i++) Answer += (R[i] - i + 1);
	cout << Answer << endl;
	return 0;
}
