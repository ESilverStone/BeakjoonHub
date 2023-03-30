import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static int[] visit;
	public static int[] arr;
	public static int[] ans;
	public static int N;
	public static int M;
	public static StringBuilder sb = new StringBuilder();
	
	public static void func(int idx, int cnt) {
		
		if(idx == M) {
			
			for(int i=0; i<M; i++) {
				sb.append(ans[i]+" ");
			}
			sb.append("\n");
			
			return;
		}
		
		for(int i=0; i<N; i++) {
			
			//if(visit[i] == 1) continue;
			
			if(idx!=0 && arr[i] < ans[idx-1]) continue;
			
			ans[idx] = arr[i];
						
			visit[i] = 1;
			func(idx+1,cnt);
			visit[i] = 0;
				
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		
		arr = new int[N];
		visit = new int[N];
		ans = new int[M];
		
		for(int i=0; i<N; i++) {
			arr[i] = sc.nextInt();
		}
		
		Arrays.sort(arr);
		
		func(0,0);
		System.out.println(sb);
	}
}