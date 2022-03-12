import java.util.Arrays;
import java.util.Scanner;

public class 1759 {

	static char[] arr;
	static boolean[] tf;
	static int c, l;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		l = sc.nextInt(); // 암호 길이
		c = sc.nextInt(); // 후보 문자
		arr = new char[c];
		tf = new boolean[c]; //백트래킹

		for (int i = 0; i < c; i++) {
			arr[i] = sc.next().charAt(0); //str을 char로 변환
		}
		Arrays.sort(arr);
		
		dfs(0, 0, 0, 0);
		sc.close();
	}

	public static void dfs(int start, int depth, int jaeum, int moeum) {

		for (int i = start; i < c; i++) {
			tf[i] = true;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				dfs(i + 1, depth + 1, jaeum, moeum + 1);
			else
				dfs(i + 1, depth + 1, jaeum + 1, moeum);
			tf[i] = false;
		}
		
		if (depth == l && jaeum >= 2 && moeum >= 1) { //조건
			for (int i = 0; i < c; i++) {
				if (tf[i] == true)
					System.out.print(arr[i]);
			}
			System.out.println("");
			return;
		}

	}
}