#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
int N, X[19], Y[19];
double dp[1 << 16][19];
 
int main() {
	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
 
	// 배열 dp 초기화
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) dp[i][j] = 1e9;
	}
 
	// 동적 계획 알고리즘(dp[지나간 도시][현재 있는 도시]로 되어 있음)
	dp[0][0] = 0;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] >= 1e9) continue;
 
			// 도시 j에서 도시 k로 이동하고 싶다!
			for (int k = 0; k < N; k++) {
				// 이미 도시 k를 통과한 경우
				if ((i / (1 << k)) % 2 == 1) continue;
 
				// 상태 전이
				double DIST = sqrt(1.0 * (X[j] - X[k]) * (X[j] - X[k]) + 1.0 * (Y[j] - Y[k]) * (Y[j] - Y[k]));
				dp[i + (1 << k)][k] = min(dp[i + (1 << k)][k], dp[i][j] + DIST);
			}
		}
	}
 
	// 답을 출력
	printf("%.12lf\n", dp[(1 << N) - 1][0]);
	return 0;
}
