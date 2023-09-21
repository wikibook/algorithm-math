// 변수 kakutei[i]는 노드 i의 최단 거리가 결정되었는지 아닌지를 나타낸다
for (int i = 1; i <= N; i++) kakutei[i] = false;
for (int i = 1; i <= N; i++) cur[i] = 2000000000;

// 최단 거리를 업데이트해 나간다
cur[1] = 0;
while (true) {
	// [조작 A] 다음으로 확정할 노드 pos를 구한다
	int pos = -1;
	int MinDist = 2000000000;
	for (int i = 1; i <= N; i++) {
		if (kakutei[i] == true || MinDist <= cur[i]) continue;
		pos = i;
		MinDist = cur[i];
	}
	if (pos == -1) break; // 다음으로 확정할 노드가 없는 경우, 조작 종료

	// [조작 B] pos와 인접한 노드의 cur 값을 업데이트
	kakutei[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i].first; // 인접한 노드의 번호
		int cost = G[pos][i].second; // 인접한 노드까지의 길이
		cur[nex] = min(cur[nex], cur[pos] + cost);
	}
}
