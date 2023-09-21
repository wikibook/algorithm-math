// 정수 x가 몇 번째에 위치하는지 반환한다
int search(int x) {
	int pos = lower_bound(A + 1, A + N + 1, x) - A;
	if (pos <= N && A[pos] == x) return pos;
	return -1;
}
