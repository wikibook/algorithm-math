#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// 사칙연산
	printf("%d\n", 869 + 120); // 989
	printf("%d\n", 869 - 120); // 749
	printf("%d\n", 869 * 120); // 104280
	printf("%d\n", 869 / 120); // 7(정수 부분만 출력하므로 주의)

	// 나머지(mod)
	printf("%d\n", 8 % 5); // 3
	printf("%d\n", 869 % 120); // 29

	// 절댓값(abs)
	printf("%d\n", abs(-45)); // 45
	printf("%d\n", abs(15)); // 15

	// 제곱(pow)
	printf("%d\n", (int)pow(10.0, 2.0)); // 100
	printf("%d\n", (int)pow(3.0, 4.0)); // 81

	// 루트(sqrt)
	printf("%.5lf\n", sqrt(4.0)); // 2.00000
	printf("%.5lf\n", sqrt(2.0)); // 1.41421
	return 0;
}