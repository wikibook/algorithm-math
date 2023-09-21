// 점수의 최댓값이 12 이상인지를 판정하고자 하는 경우, check(12)를 호출하면 된다
bool check(int x) {
	int Count = 0, Last_Kireme = 0; // Count는 현 시점에서 몇 번 잘랐는가를 나타낸다
	for (int i = 1; i <= N; i++) {
		if (A[i] - Last_Kireme >= x && L - A[i] >= x) {
			Count += 1;
			Last_Kireme = A[i];
		}
	}
	if (Count >= K) return true;
	return false;
}
