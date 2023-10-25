// 이 코드는 깊이 우선 탐색(DFS)를 스택으로 구현한 예입니다.
// 스택은 "가장 위에 요소를 추가한다", "가장 위의 요소를 확인한다", "가장 위의 요소를 꺼낸다"라는 3가지 조작을 할 수 있는 자료구조입니다.
// 깊이 우선 탐색 부분은 코드 4.5.3의 queue를 stack으로 변경한 것을 기반으로 작성했습니다.

// 인접리스트 작성 방법은 코드 4.5.1의 주석 참고

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];
bool visited[100009];

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
	
	
	// 스택 S 정의
	// 스택이 S[0], S[1], ..., S[SZ - 1]가 될 수 있게
	int S[100009], SZ = 0;
	
	// 깊이 우선 탐색 초기화
	for (i = 1; i <= N; i++) {
		visited[i] = false;
	}
	visited[1] = true;
	S[SZ] = 1; SZ++; // S에 1을 추가
	
	// 너비 우선 탐색
	while (SZ >= 1) {
		int pos = S[SZ - 1]; // S의 앞부분 확인하기
		SZ--; // S의 앞부분 추출하기
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (visited[nex] == false) {
				visited[nex] = true;
				S[SZ] = nex; SZ++; // S에 nex를 추가
			}
		}
	}
	
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