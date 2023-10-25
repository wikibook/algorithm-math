#include <stdio.h>
#include <stdlib.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];

int main() {
	// 입력
	scanf("%d%d", &N, &M);
	int i, j;
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
	
	// 답 구하기
	int answer = 0;
	for (i = 1; i <= N; i++) {
		int cnt = 0;
		for (j = 0; j < degree[i]; j++) {
			// G[i][j]는 정점 i에 인접한 정점 중 j번째 정점
			if (G[i][j] < i) {
				cnt += 1;
			}
		}
		// 자기자신보다 번호가 작은 인접한 정점이 1개 있다면, answer에 1을 추가
		if (cnt == 1) {
			answer += 1;
		}
	}
	
	// 답 출력
	printf("%d\n", answer);
	
	return 0;
}
