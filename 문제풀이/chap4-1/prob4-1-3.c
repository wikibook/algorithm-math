#include <stdio.h>
#include <math.h>
 
double X1, Y1, R1;
double X2, Y2, R2;
 
int main() {
	// 입력
	scanf("%lf%lf%lf", &X1, &Y1, &R1);
	scanf("%lf%lf%lf", &X2, &Y2, &R2);
	
	// 원 중심과의 거리 구하기
	double d = sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
	
	// 답 출력
	if (d < abs(R1 - R2)) printf("1\n");
	else if (d == abs(R1 - R2)) printf("2\n");
	else if (d < R1 + R2) printf("3\n");
	else if (d == R1 + R2) printf("4\n");
	else printf("5\n");
	return 0;
}