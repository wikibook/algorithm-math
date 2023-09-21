#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, K;
int Answer = 0;
char c[19][109], d[19][109]; // 배열 d는 칸 D에 대응

// 남은 remaining_steps번의 '열에 대응하는 조작'으로 최대 몇 개의 칸을 검은색으로 칠할 수 있는지 반환하는 함수
int paintRow(int remaining_steps) {
	// 각 열에 대한 '흰색 칸의 개수'를 계산하고 내림차순으로 정렬한다
	vector<pair<int, int>> Column;
	for (int j = 1; j <= W; j++) {
		int cnt = 0;
		for (int i = 1; i <= H; i++) {
			if (d[i][j] == '.') cnt += 1;
		}
		Column.push_back(make_pair(cnt, j));
	}
	sort(Column.begin(), Column.end());
	reverse(Column.begin(), Column.end());

	// 열에 대한 조작을 수행한다
	for (int j = 0; j < remaining_steps; j++) {
		int idx = Column[j].second;
		for (int i = 1; i <= H; i++) d[i][idx] = '#';
	}

	// 검은색 칸의 개수를 센다
	int ret = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (d[i][j] == '#') ret += 1;
		}
	}
	return ret;
}

int main() {
	// 입력
	cin >> H >> W >> K;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}

	// 비트 완전 탐색
	for (int t = 0; t < (1 << H); t++) {
		// 우선은 칸을 초기매트릭스에 설정
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) d[i][j] = c[i][j];
		}

		// 행에 대해 조작을 수행한다
		// 변수 remaining_steps는 남은 조작 횟수
		int remaining_steps = K;
		for (int i = 1; i <= H; i++) {
			int wari = (1 << (i - 1));
			if ((t / wari) % 2 == 0) continue;
			remaining_steps -= 1;
			for (int j = 1; j <= W; j++) d[i][j] = '#'; // i번째 행을 검은색으로 칠한다
		}

		// 열에 대한 조작을 수행한다
		if (remaining_steps >= 0) {
			int SubAnswer = paintRow(remaining_steps);
			Answer = max(Answer, SubAnswer);
		}
	}

	// 출력
	cout << Answer << endl;
	return 0;
}
