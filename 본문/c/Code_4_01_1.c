#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// 입력
	long long ax, ay, bx, by, cx, cy;
	scanf("%lld%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &cx, &cy);

	// 벡터 BA, BC, CA, CB의 성분 표시를 구함
	long long BAx = (ax - bx), BAy = (ay - by);
	long long BCx = (cx - bx), BCy = (cy - by);
	long long CAx = (ax - cx), CAy = (ay - cy);
	long long CBx = (bx - cx), CBy = (by - cy);

	// 어떤 패턴에 해당하는지 판정
	int pattern = 2;
	if (BAx * BCx + BAy * BCy < 0LL) pattern = 1;
	if (CAx * CBx + CAy * CBy < 0LL) pattern = 3;

	// 점과 직선의 거리 구하기
	double answer = 0.0;
	if (pattern == 1) answer = sqrt(BAx * BAx + BAy * BAy);
	if (pattern == 3) answer = sqrt(CAx * CAx + CAy * CAy);
	if (pattern == 2) {
		double S = llabs(BAx * BCy - BAy * BCx);
		double BCLength = sqrt(BCx * BCx + BCy * BCy);
		answer = S / BCLength;
	}

	// 답 출력
	printf("%.12lf\n", answer);
	return 0;
}
