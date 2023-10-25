#include <stdio.h>

int cnt = 1000;

int func1() {
	return 2021;
}

int func2(int pos) {
	cnt += 1;
	return cnt + pos;
}

int main() {
	printf("%d\n", func1()); // "2021"이라고 출력
	printf("%d\n", func2(500)); // "1501"이라고 출력
	printf("%d\n", func2(500)); // "1502"라고 출력
	return 0;
}
