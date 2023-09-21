// S = {15, 35, 50}의 상태에서 시작하는 것을 생각한다
auto itr1 = S.lower_bound(40);
cout << (*itr1) << endl; // 50이 출력된다

itr1--;
cout << (*itr1) << endl; // (1개 작다) 35가 출력된다

itr1++;
cout << (*itr1) << endl; // (1개 크다) 50이 출력된다
