import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner get = new Scanner(System.in);

        int n = get.nextInt();
        
        String[] str = new String[n+1];

        for (int i = 0; i < n; i++) {
            int count = 0, sum = 0;
            str[i] = get.next();
            for (int j =0; j < str[i].length(); j++) {
                if (str[i].charAt(j) == 'O')sum += ++count;
                else count = 0;
            }
            System.out.println(sum);
        }
        get.close();
    }
}