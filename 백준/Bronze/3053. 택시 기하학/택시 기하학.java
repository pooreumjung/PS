import java.util.Scanner;

public class Main {
	   public static void main(String[] args) {
		   Scanner sc = new Scanner(System.in);
		   	   
		   int R = sc.nextInt();
		   
		   double Euclid = Math.PI * R * R;  
		   double Taxi = 2 * R * R;
		   
		   System.out.println(String.format("%.6f",Euclid)); 
		   System.out.println(String.format("%.6f",Taxi));
	 }
}
