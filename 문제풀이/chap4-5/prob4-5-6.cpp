#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// 입력
int H, W;
int sx, sy, start; // 시작 좌표 (sx, sy)와 정점 번호 sx*H+sy
int gx, gy, goal;  // 목표 좌표 (gx, gy)와 정점 번호 gx*W+gy
char c[59][59];
 
// 그래프/최단거리
int dist[2509];
vector<int> G[2509];
 
int main() {
	// 입력
	cin >> H >> W;
	cin >> sx >> sy; start = sx * W + sy;
	cin >> gx >> gy; goal = gx * W + gy;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}
	
	// 가로 방향 엣지 [(i, j) - (i, j+1)]를 그래프에 추가
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W - 1; j++) {
			int idx1 = i * W + j; // (i, j)의 정점 번호
			int idx2 = i * W + (j+1); // (i, j+1)의 정점 번호
			if (c[i][j] == '.' && c[i][j+1] == '.'){
				G[idx1].push_back(idx2);
				G[idx2].push_back(idx1);
			}
		}
	}
	
	// 세로 방향 엣지 [(i, j) - (i+1, j)]를 그래프에 추가
	for (int i = 1; i <= H - 1; i++) {
		for (int j = 1; j <= W; j++) {
			int idx1 = i * W + j; // (i, j)의 정점 번호
			int idx2 = (i+1) * W + j; // (i+1, j)의 정점 번호
			if (c[i][j] == '.' && c[i+1][j] == '.'){
				G[idx1].push_back(idx2);
				G[idx2].push_back(idx1);
			}
		}
	}
 
	// 너비 우선 탐색 초기화(dist[i] = -1은 도달하지 않은 흰색 정점이라는 의미)
	for (int i = 1; i <= H * W; i++) dist[i] = -1;
	queue<int> Q; // 큐 Q 정의
	Q.push(start); dist[start] = 0; // Q에 1을 추가(조작1)
 
	// 너비 우선 탐색
	while (!Q.empty()) {
		int pos = Q.front(); // Q의 앞부분 확인(조작2)
		Q.pop(); // Q의 앞부분 추출(조작3)
		for (int i = 0; i < (int)G[pos].size(); i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q.push(nex); // Q에 nex를 추가(조작1)
			}
		}
	}
 
	// 답 출력
	cout << dist[goal] << endl;
	return 0;
}