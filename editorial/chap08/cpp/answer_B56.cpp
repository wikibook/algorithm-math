#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 입력으로 주어지는 변수 등
int N, Q, L[100009], R[100009];
string S;
string SRev; // S의 역순

// 문자열을 숫자로 변환한 값(각각 S, SRev에 해당)
int T[100009];
int TRev[100009];

// 해시값 등
long long mod = 2147483647;
long long Power100[100009];
long long H[100009];    // S의 해쉬값
long long HRev[100009]; // SRev의 해시

// 문자열의 l~r번째를 앞쪽에서 읽었을 때의 해시값을 반환하는 함수
long long GetHashLeft(int l, int r) {
	long long val = H[r] - (Power100[r - l + 1] * H[l - 1] % mod);
	if (val < 0) val += mod;
	return val;
}

// 문자열의 l~r번째를 뒤에서 읽었을 때 해시값을 반환하는 함수
long long GetHashRight(int l, int r) {
	int true_l = N + 1 - r;
	int true_r = N + 1 - l;
	long long val = HRev[true_r] - (Power100[true_r - true_l + 1] * HRev[true_l - 1] % mod);
	if (val < 0) val += mod;
	return val;
}

int main() {
	// 입력
	cin >> N >> Q;
	cin >> S;
	for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];
	SRev = S;
	reverse(SRev.begin(), SRev.end());

	// S, SRev 문자를 숫자로 변환
	for (int i = 1; i <= N; i++) T[i] = (int)(S[i - 1] - 'a') + 1;
	for (int i = 1; i <= N; i++) TRev[i] = (int)(SRev[i - 1] - 'a') + 1;

	// 100의 n 제곱을사전 계산
	Power100[0] = 1;
	for (int i = 1; i <= N; i++) Power100[i] = (100LL * Power100[i - 1]) % mod;

	// S의 해시값을사전 계산
	H[0] = 1;
	for (int i = 1; i <= N; i++) H[i] = (100LL * H[i - 1] + T[i]) % mod;

	// SRev의 해시값을사전 계산
	HRev[0] = 1;
	for (int i = 1; i <= N; i++) HRev[i] = (100LL * HRev[i - 1] + TRev[i]) % mod;

	// 쿼리 처리
	for (int i = 1; i <= Q; i++) {
		long long v1 = GetHashLeft(L[i], R[i]);
		long long v2 = GetHashRight(L[i], R[i]);
		// 왼쪽에서 읽었을 때와 오른쪽에서 읽었을 때의 해쉬값이 일치하면 회문
		if (v1 == v2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
