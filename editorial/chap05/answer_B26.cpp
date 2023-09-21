#include <iostream>
using namespace std;

int N;
bool Deleted[1000009]; // 정수 x가 지워진 경우에 한해 Deleted[x]=true

int main() {
	// 입력
	cin >> N;

	// 엘라토스테네스의 체 (i는 √N 이하의 최대 정수까지 반복)
	for (int i = 2; i <= N; i++) Deleted[i] = false;
	for (int i = 2; i * i <= N; i++) {
		if (Deleted[i] == true) continue;
		for (int j = i * 2; j <= N; j += i) Deleted[j] = true;
	}

	// 답을 출력
	for (int i = 2; i <= N; i++) {
		if (Deleted[i] == false) cout << i << endl;
	}
	return 0;
}
