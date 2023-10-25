#include <stdio.h>
#include <stdlib.h>

int H, W, sx, sy, gx, gy, start, goal; char c[59][59];

int edges, A[5009], B[5009], degree[2509], cnt[2509];
int* G[2509];
int dist[2509];

int main() {
	// 입력
	scanf("%d%d", &H, &W);
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &gx, &gy);
	int i, j;
	for (i = 1; i <= H; i++) {
		scanf("%s", c[i] + 1); // 입력한 문자열을 c[i][1], c[i][2], ...에 저장(인덱스 1부터 저장)
	}
	start = (sx - 1) * W + sy;
	goal = (gx - 1) * W + gy;
	
	// 그래프의 엣지 리스트업(edges는 현재 엣지 수)
	edges = 0;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W - 1; j++) {
			if (c[i][j] == '.' && c[i][j + 1] == '.') {
				edges += 1;
				A[edges] = (i - 1) * W + j; // (i, j)의 정점 번호
				B[edges] = (i - 1) * W + (j + 1); // (i, j + 1)의 정점 번호
			}
		}
	}
	for (i = 1; i <= H - 1; i++) {
		for (j = 1; j <= W; j++) {
			if (c[i][j] == '.' && c[i + 1][j] == '.') {
				edges += 1;
				A[edges] = (i - 1) * W + j; // (i, j)의 정점 번호
				B[edges] = i * W + j; // (i + 1, j)의 정점 번호
			}
		}
	}
	
	// 인접리스트 작성(~/codes/c/Code_4_5_1.c 참고)
	for (i = 1; i <= H * W; i++) degree[i] = 0;
	for (i = 1; i <= edges; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	for (i = 1; i <= H * W; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	for (i = 1; i <= H * W; i++) cnt[i] = 0;
	for (i = 1; i <= edges; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 큐 Q 정의 → 너비 우선 탐색 초기화(~/codes/c/Code_4_5_3.c 참고)
	int Q[2509];
	int QL = 0, QR = 0;
	for (i = 1; i <= H * W; i++) {
		dist[i] = -1;
	}
	dist[start] = 0;
	Q[QR] = start; QR++; // Q에 start를 추가
	
	// 너비 우선 탐색(~/codes/c/Code_4_5_3.c 참고)
	while (QL != QR) {
		int pos = Q[QL]; // Q의 앞부분 확인
		QL++; // Q의 앞부분 추출
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q[QR] = nex; QR++; // Q에 nex를 추가
			}
		}
	}
	
	// 답 출력
	printf("%d\n", dist[goal]);
	
	return 0;
}
