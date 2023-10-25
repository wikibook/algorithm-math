// 인접리스트 작성 방법은 코드 4.5.1의 주석 참고

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];
int dist[100009];

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
	
	
	// 큐 Q 정의
	// 큐가 Q[QL], Q[QL+1], ..., Q[QR-1]가 될 수 있게
	int Q[100009];
	int QL = 0, QR = 0;
	
	// 너비 우선 탐색 초기화(dist[i] = -1일 때, 미도달 흰색 정점으로 판단)
	for (i = 1; i <= N; i++) {
		dist[i] = -1;
	}
	dist[1] = 0;
	Q[QR] = 1; QR++; // Q에 1을 추가(조작1)
	
	// 너비 우선 탐색
	while (QL != QR) {
		int pos = Q[QL]; // Q의 앞부분 확인(조작2)
		QL++; // Q의 앞부분 추출(조작3)
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q[QR] = nex; QR++; // Q에 nex를 추가(조작1)
			}
		}
	}
	
	// 정점1에서 각 정점까지의 최단 거리를 출력
	for (i = 1; i <= N; i++) {
		printf("%d\n", dist[i]);
	}
	
	// 인접리스트 G 제거
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}