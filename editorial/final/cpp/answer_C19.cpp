#include <iostream>
#include <algorithm>
using namespace std;

class SegmentTree {
public:
	long long dat[2100000], siz = 1;

	// 요소 dat의 초기화를 수행한다(최초에는 전부 0)
	void init(int N) {
		siz = 1;
		while (siz < N) siz *= 2;
		for (int i = 1; i < siz * 2; i++) dat[i] = 0;
	}

	// 쿼리 1에 대한 처리
	void update(int pos, long long x) {
		pos = pos + siz - 1;
		dat[pos] = x;
		while (pos >= 2) {
			pos /= 2;
			dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}

	// 쿼리 2에 대한 처리
	// u는 현재의 셀 번호, [a, b)는 셀에 대응하는 반개구간, [l, r)은 구할 반개구간
	long long query(int l, int r, int a, int b, int u) {
		if (r <= a || b <= l) return (1LL << 60); // 전혀 포함되지 않는 경우
		if (l <= a && b <= r) return dat[u]; // 완전히 포함된 경우
		int m = (a + b) / 2;
		long long AnswerL = query(l, r, a, m, u * 2);
		long long AnswerR = query(l, r, m, b, u * 2 + 1);
		return min(AnswerL, AnswerR);
	}
};

long long N, L, K;
long long A[700009], C[700009];
long long Min_Value[700009];
SegmentTree Z;

int main() {
	// 입력
	cin >> N >> L >> K;
	for (int i = 1; i <= N; i++) cin >> A[i] >> C[i];

	// 각 지점에서의 '가격의 최소값'을 구한다
	for (int i = 1; i <= L - 1; i++) Min_Value[i] = (1LL << 60);
	for (int i = 1; i <= N; i++) Min_Value[A[i]] = min(Min_Value[A[i]], C[i]);

	// 세그먼트 트리에 올리기
	Z.init(L);
	for (int i = 1; i <= L - 1; i++) Z.update(i, Min_Value[i]);

	// 답을 구한다
	long long Answer = 0;
	for (int i = 1; i <= L - K; i++) {
		long long val = Z.query(i, i + K, 1, Z.siz + 1, 1);
		if (val == (1LL << 60)) {
			cout << "-1" << endl;
			return 0;
		}
		Answer += val;
	}
	cout << Answer << endl;
	return 0;
}
