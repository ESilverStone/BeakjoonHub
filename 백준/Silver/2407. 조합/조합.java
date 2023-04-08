import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        
        // r이 n-r보다 큰 경우 r을 n-r로 바꿔 계산한다.
        r = Math.min(r, n-r);
        
        BigInteger numerator = BigInteger.valueOf(1);
        BigInteger denominator = BigInteger.valueOf(1);
        
        for (int i = 1; i <= r; i++) {
            numerator = numerator.multiply(BigInteger.valueOf(n-i+1));
            denominator = denominator.multiply(BigInteger.valueOf(i));
        }
        
        BigInteger answer = numerator.divide(denominator);
        System.out.println(answer);
        
        sc.close();
    }
}