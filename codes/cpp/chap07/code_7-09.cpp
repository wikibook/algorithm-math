// X[t]=x, Y[t]=y, H[t]=h로 변경하는 함수
void Change(int t, int x, int y, int h) {
	// X[t], Y[t], H[t]의 변경
	X[t] = x;
	Y[t] = y;
	H[t] = h;

	// 배열 B 리셋(0으로 되돌린다)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) B[i][j] = 0;
	}

	// 배열 B 업데이트
	for (int q = 1; q <= Q; q++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				B[j][i] += max(0, H[q] - abs(X[q] - i) - abs(Y[q] - j));
			}
		}
	}
}
