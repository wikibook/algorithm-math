// 연상 배열 정의   | map<첨자_타입, 타입>의 형태
// 연상 배열의 접근  | 일반적인 배열과 거의 같음
// ----------------------------------------------------------------

// 첨자가 string 타입, 기록하는 값이 int 타입인 연상 배열을 정의
map<string, int> Map;

// 연상 배열 접근
Map["tanaka"] = 49;
Map["suzuki"] = 50;
cout << Map["tanaka"] << endl; // 49가 출력된다
cout << Map["suzuki"] << endl; // 50이 출력된다

Map["suzuki"] = 53;
cout << Map["suzuki"] << endl; // 53이 출력된다
cout << Map["sato"] << endl; // 0이 출력된다
