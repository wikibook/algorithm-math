// C에서는 C++의 vector<int> 등을 사용할 수 없으므로, 다음과 같은 과정을 거쳐서 인접리스트를 구축합니다.
// 과정1. 각 정점의 차수를 degree[i]로 셉니다.
// 과정2. 각 G[i]의 메모리를 malloc으로 동적 확보합니다.
// 과정3. 확보된 G[i]에 엣지를 정보를 할당합니다.


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
	
	// 출력
	for (i = 1; i <= N; i++) {
		printf("%d: {", i);
		for (j = 0; j < degree[i]; j++) {
			if (j >= 1) printf(","); // 쉼표로 구분해서 출력
			printf("%d", G[i][j]); // G[i][j]는 정점i와 인접한 정점 중에서 j번째 정점
		}
		printf("}\n");
	}
	
	// 인접리스트 G 제거
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}
