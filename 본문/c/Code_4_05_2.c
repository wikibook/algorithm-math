// 인접리스트 작성 방법은 코드 4.5.1의 주석 참고

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];

bool visited[100009];

void dfs(int pos) {
	visited[pos] = true;
	int i;
	for (i = 0; i < degree[pos]; i++) {
		if (visited[G[pos][i]] == false) {
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
	
	// 각 정점의 차수 세기(과정1)
	for (i = 1; i <= N; i++) degree[i] = 0;
	for (i = 1; i <= M; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	
	// 인접리스트 G 만들기(과정2)
	for (i = 1; i <= N; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	
	// G에 엣지 정보 추가하기(과정3)
	for (i = 1; i <= N; i++) cnt[i] = 0;
	for (i = 1; i <= M; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 깊이 우선 탐색
	for (i = 1; i <= N; i++) {
		visited[i] = false;
	}
	dfs(1);
	
	// 연결되어 있는지 판정(Answer=true라면 연결됨)
	bool answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			answer = false;
		}
	}
	if (answer == true) {
		printf("The graph is connected.\n");
	}
	else {
		printf("The graph is not connected.\n");
	}
	
	// 인접리스트 G 제거
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}