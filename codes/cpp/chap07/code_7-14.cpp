// 01	// A[Left], A[Left+1], …, A[Right-1]의 최댓값을 구하는 함수
int GetMax(int Left, int Right) {
	// 구간에 포함된 요소가 1개가 된 경우
	if (Right - Left == 1) return A[Left];
	// 왼쪽 반과 오른쪽 반을 분할한다
	int Mid = (Left + Right) / 2;
	int res1 = GetMax(Left, Mid); // res1은 '왼쪽 반의 최댓값'
	int res2 = GetMax(Mid, Right); // res2는 '오른쪽 반의 최댓값'
	return max(res1, res2);
}
