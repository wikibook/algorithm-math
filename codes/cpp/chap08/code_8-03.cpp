auto itr = S.lower_bound(x);
if (itr == S.end()) { // x가 S의 최댓값보다 클 때 itr==S.end()를 만족한다
	cout << "-1" << endl; // 이런 경우는 -1을 출력
}
else {
	cout << (*itr) << endl; // 그렇지 않은 경우는 일반적으로 처리
}
