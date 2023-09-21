#include <iostream>
#include <string>
#include <map>
using namespace std;

int Q;
int QueryType[100009], y[100009];
string x[100009];
map<string, int> Map;

int main() {
	// 입력
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> QueryType[i];
		if (QueryType[i] == 1) cin >> x[i] >> y[i];
		if (QueryType[i] == 2) cin >> x[i];
	}

	// 쿼리 처리
	for (int i = 1; i <= Q; i++) {
		if (QueryType[i] == 1) Map[x[i]] = y[i];
		if (QueryType[i] == 2) cout << Map[x[i]] << endl;
	}
	return 0;
}
