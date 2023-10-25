#include <iostream>
using namespace std;

long long N, A[200009];
long long cnt[100009];
long long Answer = 0;

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// cnt[1], cnt[2], ..., cnt[99999] 세기
	for (int i = 1; i <= 99999; i++) cnt[i] = 0;
	for (int i = 1; i <= N; i++) cnt[A[i]] += 1;
	
	// 답 구하기
	for (int i = 1; i <= 49999; i++) {
		Answer += cnt[i] * cnt[100000 - i];
	}
	Answer += cnt[50000] * (cnt[50000] - 1) / 2;
	
	// 출력
	cout << Answer << endl;
	return 0;
}