import java.util.Arrays;
import java.util.Scanner;

public class 1546 {
	public static void main(String[] args){
 
		Scanner get = new Scanner(System.in);
 
		double arr[] = new double[get.nextInt()];
		
		for(int i = 0; i < arr.length; i++){
			arr[i] = get.nextDouble();
		}
        get.close();
		
		double sum = 0;
		Arrays.sort(arr);
		
		for(int i = 0; i < arr.length; i++){
            double s = (arr[i]/arr[arr.length-1]*100);
			sum += s;
		}
		System.out.print( sum/arr.length );
	}
}