set<int> S;

// 조작을 수행한다
S.insert(1); // S = {1}
S.insert(2); // S = {1, 2}
S.insert(4); // S = {1, 2, 4}
S.insert(2); // S = {1, 2, 4} ← 여기에서 {1, 2, 2, 4}가 되지 않는 것에 주의!
cout << S.size() << endl; // 3이 출력된다

S.erase(2); // S = {1, 4}
S.insert(9); // S = {1, 4, 9}
S.insert(9); // S = {1, 4, 9} ← 여기에서 {1, 4, 9, 9}가 되지 않는 것에 주의!
cout << S.size() << endl; // 3이 출력된다

if (S.count(2) == 1) cout << "2 is included" << endl; // 출력되지 않는다
if (S.count(9) == 1) cout << "9 is included" << endl; // 출력된다
