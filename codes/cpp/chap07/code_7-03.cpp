// 0번째 수의 상태를 설정
// NumState[i]는 i번째 수 시점에서의 상태 수(반드시 빔 폭 이하가 된다)
// 0번째 수는 X=[0,0,...,0]만 존재하므로 NumState[0]=1
NumState[0] = 1;
Beam[0][0].score = 0;
for (int i = 1; i <= N; i++) Beam[0][0].X[i] = 0;

// 빔 서치
for (int i = 1; i <= T; i++) {
	vector<State> Candidate;
	for (int j = 0; j < NumState[i - 1]; j++) {
		// 조작 A인 경우
		State SousaA = Beam[i - 1][j];
		SousaA.LastMove = 'A';
		SousaA.LastPos = j;
		SousaA.X[P[i]] += 1;
		SousaA.X[Q[i]] += 1;
		SousaA.X[R[i]] += 1;
		for (int k = 1; k <= N; k++) {
			if (SousaA.X[k] == 0) SousaA.score += 1;
		}

		// 조작 B인 경우
		State SousaB = Beam[i - 1][j];
		SousaB.LastMove = 'B';
		SousaB.LastPos = j;
		SousaB.X[P[i]] -= 1;
		SousaB.X[Q[i]] -= 1;
		SousaB.X[R[i]] -= 1;
		for (int k = 1; k <= N; k++) {
			if (SousaB.X[k] == 0) SousaB.score += 1;
		}

		// 후보에 추가
		Candidate.push_back(SousaA);
		Candidate.push_back(SousaB);
	}

	// 정렬해서 Beam[i]의 결과를 계산한다
	sort(Candidate.begin(), Candidate.end(), greater<State>());
	NumState[i] = min(WIDTH, (int)Candidate.size());
	for (int j = 0; j < NumState[i]; j++) Beam[i][j] = Candidate[j];
}
