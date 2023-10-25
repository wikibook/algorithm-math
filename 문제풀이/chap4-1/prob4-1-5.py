# 벡터 (ax, ay)와 (bx, by) 외적의 크기
def cross(ax, ay, bx, by):
	return ax * by - ay * bx

# 입력
X1, Y1 = map(int, input().split())
X2, Y2 = map(int, input().split())
X3, Y3 = map(int, input().split())
X4, Y4 = map(int, input().split())

# cross 값 계산
ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);

# 모두 일직선 위에 있는 경우(코너 케이스)
if ans1 == 0 and ans2 == 0 and ans3 == 0 and ans4 == 0:
	# A, B, C, D를 숫자 값(정확하게는 pair 자료형)으로 변환
	# 적당하네 swap해서 A<B, C<D가 되게 만듦
	# 이렇게 하면 구간 중첩 판정(절말문제 2.5.6)처럼 풀 수 있음
	A = (X1, Y1) # 점A의 좌표
	B = (X2, Y2) # 점B의 좌표
	C = (X3, Y3) # 점C의 좌표
	D = (X4, Y4) # 점D의 좌표
	if A > B:
		tmp = B
		B = A
		A = tmp
	if C > D:
		tmp = D
		D = C
		C = tmp
	if max(A, C) <= min(B, D):
		print("Yes")
	else:
		print("No")

# 그렇지 않은 일반적인 경우
else:
	IsAB = False # IsAB: 선분 AB가 점 C, D를 나누는가?
	IsCD = False # IsCD: 선분 CD가 점 A, B를 나누는가?
	if ans1 >= 0 and ans2 <= 0:
		IsAB = True
	if ans1 <= 0 and ans2 >= 0:
		IsAB = True
	if ans3 >= 0 and ans4 <= 0:
		IsCD = True
	if ans3 <= 0 and ans4 >= 0:
		IsCD = True
	
	# 답 출력
	if IsAB == True and IsCD == True:
		print("Yes")
	else:
		print("No")