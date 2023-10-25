import java.util.*;

class Code_5_10_4 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		
		// (의 수에서 )의 수를 뺀 값을 depth에 할당합니다.
		// 중간에 depth가 음수가 된다면, 곧바로 답이 No입니다.
		int depth = 0;
		boolean flag = true;
		for (int i = 0; i < N; i++) {
			if (S.charAt(i) == '(') {
				depth += 1;
			}
			if (S.charAt(i) == ')') {
				depth -= 1;
			}
			if (depth < 0) {
				flag = false;
			}
		}
		
		// 마지막으로 depth = 0[(와 )의 수가 같음]을 추가적으로 판정합니다.
		if (flag == true && depth == 0) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
