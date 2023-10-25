#include <iostream>
#include <algorithm>
using namespace std;

long long N, K, X[59], Y[59];
long long Answer = (1LL << 62); // 나올 수 없는 값을 설정

int check_numpoints(int lx, int rx, int ly, int ry) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		// 점(X[i], Y[i])가 직사각형에 포함되어 있는지 판정
		if (lx <= X[i] && X[i] <= rx && ly <= Y[i] && Y[i] <= ry) cnt++;
	}
	return cnt;
}

int main() {
	// 입력
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 왼쪽 끝 x, 오른쪽 끝 x, 아래쪽 끝 y, 위쪽 끝 y를 전체 탐색(각각 번호가 i, j, k, l)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				for (int l = 1; l <= N; l++) {
					int cl = X[i]; // 왼쪽 끝의 x 좌표
					int cr = X[j]; // 오른쪽 끝의 x 좌표
					int dl = Y[k]; // 아래쪽 끝의 y 좌표
					int dr = Y[l]; // 위쪽 끝의 y 좌표
					if (check_numpoints(cl, cr, dl, dr) >= K) {
						long long area = 1LL * (cr - cl) * (dr - dl);
						Answer = min(Answer, area);
					}
				}
			}
		}
	}

	// 답 출력
	cout << Answer << endl;
	return 0;
}