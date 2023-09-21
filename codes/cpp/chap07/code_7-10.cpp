void Yamanobori() {
	// 변수 설정(5.95초 동안 루프를 돌린다/ CLOCKS_PER_SEC는 1초가 몇 밀리초인지를 나타낸다)
	int TIMELIMIT = 5.95 * CLOCKS_PER_SEC;
	int CurrentScore = GetScore();
	int ti = clock();

	// 등산 알고리즘 시작
	while (clock() - ti < TIMELIMIT) {
		// (t, new_x, new_y, new_h) 조합을 무작위로 선택한다
		// 함수 RandInt은 7.2절의 해답 예를 참조한다
		int t = RandInt(1, Q);
		int old_x = X[t], new_x = X[t] + RandInt(-9, 9);
		int old_y = Y[t], new_y = Y[t] + RandInt(-9, 9);
		int old_h = H[t], new_h = H[t] + RandInt(-19, 19);
		if (new_x < 0 || new_x >= N) continue;
		if (new_y < 0 || new_y >= N) continue;
		if (new_h <= 0 || new_h > N) continue;

		// 일단 변경하고, 점수를 평가한다
		Change(t, new_x, new_y, new_h);
		int NewScore = GetScore();

		// 점수에 따라 채용 여부를 결정한다
		if (CurrentScore < NewScore) CurrentScore = NewScore;
		else Change(t, old_x, old_y, old_h);
	}
}
