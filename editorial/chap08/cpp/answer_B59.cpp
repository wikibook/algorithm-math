#include <iostream>
#include <algorithm>
using namespace std;
 
class SegmentTree {
public:
	int dat[600000], siz = 1;
 
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
			dat[pos] = dat[pos * 2] + dat[pos * 2 + 1]; // 8.8절에서 변경한 부분
		}
	}
 
	// 쿼리 2에 대한 처리
	int query(int l, int r, int a, int b, int u) {
		if (r <= a || b <= l) return 0; // 8.8절에서 변경한 부분
		if (l <= a && b <= r) return dat[u];
		int m = (a + b) / 2;
		int AnswerL = query(l, r, a, m, u * 2);
		int AnswerR = query(l, r, m, b, u * 2 + 1);
		return AnswerL + AnswerR; // 8.8절에서 변경한 부분
	}
};
 
int N, A[150009];
SegmentTree Z;
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 세그먼트 트리 준비
	Z.init(N);
 
	// 답을 구한다
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer += Z.query(A[i] + 1, N + 1, 1, Z.siz + 1, 1);
		Z.update(A[i], 1);
	}
 
	// 출력
	cout << Answer << endl;
	return 0;
}
