#include <iostream>
#include <algorithm>
using namespace std;
 
class SegmentTree {
public:
	int dat[300000], siz = 1;
 
	// 요소 dat의 초기화를 수행한다(최초에는 전부 0)
	void init(int N) {
		siz = 1;
		while (siz < N) siz *= 2;
		for (int i = 1; i < siz * 2; i++) dat[i] = 0;
	}
 
	// 쿼리 1에 대한 처리
	void update(int pos, int x) {
		pos = pos + siz - 1;
		dat[pos] = x;
		while (pos >= 2) {
			pos /= 2;
			dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}
 
	// 쿼리 2에 대한 처리
	// u는 현재의 셀 번호, [a, b)는 셀에 대응하는 반개구간, [l, r)은 구할 반개구간
	int query(int l, int r, int a, int b, int u) {
		if (r <= a || b <= l) return 1000000000; // 전혀 포함되지 않는 경우
		if (l <= a && b <= r) return dat[u]; // 완전히 포함된 경우
		int m = (a + b) / 2;
		int AnswerL = query(l, r, a, m, u * 2);
		int AnswerR = query(l, r, m, b, u * 2 + 1);
		return min(AnswerL, AnswerR);
	}
};
 
int N, L, R, X[100009];
int dp[100009];
SegmentTree Z;
 
int main() {
	// 입력
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) cin >> X[i];
 
	// 세그먼트 트리 준비
	Z.init(N);
	dp[1] = 0;
	Z.update(1, 0);
 
	// 동적 계획 알고리즘
	for (int i = 2; i <= N; i++) {
		int posL = lower_bound(X + 1, X + N + 1, X[i] - R) - X;
		int posR = lower_bound(X + 1, X + N + 1, X[i] - L + 1) - X - 1;
		dp[i] = Z.query(posL, posR + 1, 1, Z.siz + 1, 1) + 1;
		Z.update(i, dp[i]);
	}
 
	// 답을 출력
	cout << dp[N] << endl;
	return 0;
}
