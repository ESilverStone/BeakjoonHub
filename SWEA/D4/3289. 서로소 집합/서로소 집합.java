import java.util.Scanner;

public class Solution {
	public static int[] p;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		StringBuilder sb = new 
				StringBuilder();
		
		for(int t=0; t<T; t++) {
			
			sb.append("#"+(t+1)+" ");
			
			
			
			int n = sc.nextInt();
			int m = sc.nextInt();
			
			p = new int[n];
			
			for(int i=0; i<n; i++) {
				makeset(i);
			}
			
			for(int i=0; i<m; i++) {
				int cmd = sc.nextInt();
				
				int num1 = sc.nextInt()-1;
				int num2 = sc.nextInt()-1;
				
				
				// 합병하라
				if(cmd == 0) {
					union(num1, num2);
					findset(num1);
					findset(num2);
					
				}
				// 확인
				else {
					if(findset(num1) == findset(num2))
					{
						sb.append(1);
					}
					else sb.append(0);
				}
			}
			
			sb.append("\n");
			
		}
		System.out.println(sb);
	}
	
	public static void makeset(int x) {
		p[x] = x;
	}
	
	public static int findset(int x) {
		if(x != p[x]) p[x] = findset(p[x]);
		return p[x];
	}
	
	static void union(int x, int y) {
		p[findset(y)] = findset(x);		
	}
}