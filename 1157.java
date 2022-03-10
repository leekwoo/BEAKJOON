import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner get = new Scanner(System.in);
        String str = get.nextLine().toUpperCase();

        int[] eng = new int[26];
        int max = 0;
        char result = '?';

        for (int i = 0; i < str.length(); i++) {
            eng[str.charAt(i) - 65]++;
            if (max < eng[str.charAt(i) - 65]) {
                max = eng[str.charAt(i) - 65];
                result = str.charAt(i);
            } else if (max == eng[str.charAt(i) - 65]) {
                result = '?';
            }
        }
        get.close();
        
        System.out.println(result);
    }
}