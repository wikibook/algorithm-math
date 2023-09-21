#include <iostream>
using namespace std;

// 입력으로 주어지는 변수
long long N, Q;
string S;
long long a[200009], b[200009], c[200009], d[200009];

// 해시값을 계산하기 위한 함수
long long mod = 2147483647;
long long T[200009], H[200009];
long long Power100[200009];

// S[l, r]의 해시값을 반환하는 함수
// 나머지 계산에 주의!(5.3절)
long long Hash_value(int l, int r) {
	long long val = H[r] - (H[l - 1] * Power100[r - l + 1] % mod);
	if (val < 0) val += mod;
	return val;
}

int main() {
	// 입력
	cin >> N >> Q;
	cin >> S;
	for (int i = 1; i <= Q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

	// 문자를 수치로 변환(C++의 문자열은 0번째부터 시작하는 것에 주의!)
	for (int i = 1; i <= N; i++) T[i] = (S[i - 1] - 'a') + 1;

	// 100의 n 제곱(본문 중의 B^0, B^1, ...에 대응)을 먼저 계산한다
	Power100[0] = 1;
	for (int i = 1; i <= N; i++) Power100[i] = 100LL * Power100[i - 1] % mod;

	// H[1], ..., H[N]를 계산한다
	H[0] = 0;
	for (int i = 1; i <= N; i++) H[i] = (100LL * H[i - 1] + T[i]) % mod;

	// 쿼리에 답한다
	for (int i = 1; i <= Q; i++) {
		long long Hash1 = Hash_value(a[i], b[i]);
		long long Hash2 = Hash_value(c[i], d[i]);
		if (Hash1 == Hash2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
