// u는 현재 셀 번호, [a, b)는 셀에 대응하는 반개구간, [l, r)은 구할 반개구간
// 반개구간 [l, r)의 최댓값을 구하려면 query(l, r, 1, siz+1, 1)을 호출하면 된다
int query(int l, int r, int a, int b, int u) {
	if (r <= a || b <= l) return -1000000000; // 전혀 포함되지 않는 경우
	if (l <= a && b <= r) return dat[u]; // 완전히 포함되는 경우
	int m = (a + b) / 2;
	int AnswerL = query(l, r, a, m, u * 2);
	int AnswerR = query(l, r, m, b, u * 2 + 1);
	return max(AnswerL, AnswerR);
}
