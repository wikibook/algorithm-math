// 노드 x의 루트를 반환하는 함수
// 주: 부모를 갖지 않는 노드의 경우에는 'par[x] = -1'로 기록한다
int root(int x) {
	while (true) {
		if (par[x] == -1) break; // 1개 앞(부모)이 없으면 여기가 루트
		x = par[x]; // 1 개 앞(부모)으로 진행한다
	}
	return x;
}
