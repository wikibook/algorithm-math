#include <stdio.h>

int N, K; long long X[59], Y[59];

int check_numpoints(long long lx, long long rx, long long ly, long long ry) {
	int cnt = 0;
	int i;
	for (i = 1; i <= N; i++) {
		// 점(X[i], Y[i])가 직사각형에 포함되어 있는지 판정
		if (lx <= X[i] && X[i] <= rx && ly <= Y[i] && Y[i] <= ry) {
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	// 입력
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld", &X[i], &Y[i]);
	}

	// 왼쪽 끝 x, 오른쪽 끝 x, 아래쪽 끝 y, 위쪽 끝 y를 전체 탐색(각각 번호가 i, j, k, l)
	long long answer = (1LL << 62); // 일단 나올 수 없는 값을 설정
	int i, j, k, l;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 1; k <= N; k++) {
				for (l = 1; l <= N; l++) {
					long long cl = X[i]; // 왼쪽 끝의 x 좌표
					long long cr = X[j]; // 오른쪽 끝의 x 좌표
					long long dl = Y[k]; // 아래쪽 끝의 y 좌표
					long long dr = Y[l]; // 위쪽 끝의 y 좌표
					if (check_numpoints(cl, cr, dl, dr) >= K) {
						long long area = (cr - cl) * (dr - dl);
						if (answer > area) {
							answer = area;
						}
					}
				}
			}
		}
	}

	// 답 출력
	printf("%lld\n", answer);
	return 0;
}
