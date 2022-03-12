import java.util.*;
 
public class Main {
    public static void main(String[] args){
        
        Scanner get = new Scanner(System.in);
        
        int n = get.nextInt();
        
        int sum=0;
        String str = get.next();
        
        for(int i=0; i<n; i++) {            
            sum += str.charAt(i)-'0';            
        }
        
        System.out.println(sum);
    }
}