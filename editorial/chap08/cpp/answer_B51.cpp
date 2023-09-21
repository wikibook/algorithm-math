#include <iostream>
#include <stack>
using namespace std;
 
int main() {
	// 입력
	string S;
	cin >> S;
 
	// 왼쪽부터 순서대로 살펴본다
	// 문자열은 0번째 문자부터 시작한다는 점에 유의하세요.
	stack<int> Stack;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') {
			Stack.push(i + 1);
		}
		if (S[i] == ')') {
			cout << Stack.top() << " " << i + 1 << endl;
			Stack.pop();
		}
	}
	return 0;
}
