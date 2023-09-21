// dist[i]의 값은 ∞ 대신 매우 큰 값으로 설정
dist[1] = 0;
for (int i = 2; i <= N; i++) dist[i] = 1000000000;

// 벨만-포드 알고리즘
for (int i = 1; i <= N - 1; i++) {
	for (int j = 1; j <= M; j++) {
		dist[B[j]] = min(dist[B[j]], dist[A[j]] + C[j]);
	}
}

// 답을 출력
for (int i = 1; i <= N; i++) cout << dist[i] << endl;
