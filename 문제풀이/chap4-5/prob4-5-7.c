#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[200009], B[200009]; // N, M ≦ 200000이므로 배열의 크기를 200009 정도로 설정했습니다.
int degree[200009], cnt[200009];
int* G[200009];

int color[200009];

void dfs(int pos) {
	int i;
	for (i = 0; i < degree[pos]; i++) {
		if (color[G[pos][i]] == 0) {
			// color[pos] = 1일 때 2, color[pos] = 2일 때 1
			color[G[pos][i]] = 3 - color[pos];
			dfs(G[pos][i]);
		}
	}
}

int main() {
	// 입력
	scanf("%d%d", &N, &M);
	int i;
	for (i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}
	
	// 인접리스트 작성(~/codes/c/Code_4_5_1.c 참고)
	for (i = 1; i <= N; i++) degree[i] = 0;
	for (i = 1; i <= M; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	for (i = 1; i <= N; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	for (i = 1; i <= N; i++) cnt[i] = 0;
	for (i = 1; i <= M; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 깊이 우선 탐색
	for (i = 1; i <= N; i++) {
		color[i] = 0;
	}
	for (i = 1; i <= N; i++) {
		if (color[i] == 0) {
			// 정점 i가 흰색인 경우(아직 방문하지 않은 연결 성분인 경우)
			color[i] = 1;
			dfs(i);
		}
	}
	
	// 이분 그래프인지 판정
	bool answer = true;
	for (i = 1; i <= M; i++) {
		if (color[A[i]] == color[B[i]]) {
			answer = false;
		}
	}
	if (answer == true) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	
	return 0;
}
