#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	char answer[100] = ""; // char 자료형 배열은 문자열을 나타냄
	while (N >= 1) {
		// N % 2는 N를 2로 나눈 나머지(예: N = 13의 경우 1)
		// N / 2는 N를 2로 나눈 몫(예:N = 13의 경우 6)
		char next_answer[101];
		if (N % 2 == 0) {
			// next_answer에 "0"과 answer를 연결한 값을 할당
			sprintf(next_answer, "0%s", answer);
		}
		if (N % 2 == 1) {
			// next_answer에 "1"과 answer를 연결한 값을 할당
			sprintf(next_answer, "1%s", answer);
		}
		strcpy(answer, next_answer);
		N = N / 2;
	}
	printf("%s\n", answer);
	return 0;
}
