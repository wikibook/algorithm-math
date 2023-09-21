for (int d = 1; d <= D; d++) {
	int Answer = 0;

	// for 문으로 최댓값을 계산한다(변수 i는 방 번호를 나타낸다)
	for (int i = 1; i <= N; i++) {
		if (L[d] <= i && i <= R[d]) continue;
		Answer = max(Answer, A[i]);
	}
	cout << Answer << endl;
}
