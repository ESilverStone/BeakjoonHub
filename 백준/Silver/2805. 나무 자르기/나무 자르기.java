import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] arr = new int[N];
		
		st = new StringTokenizer(br.readLine());
	
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr);
		int min=0, max=arr[N-1];
		int mid;
		long sum = 0;
		
		while(min < max) {
			// 초기화
			mid = (min + max) / 2;
			sum = 0;
			
			for(int i=N-1; i>=0; i--) {
				if(arr[i] <= mid) break;
				else sum += (arr[i] - mid);
			}
			
			if(sum < M) {
				max = mid;
			} else {
				min = mid + 1;
			}
			//System.out.println(mid);
		}
		
		System.out.println(min-1);	
	}
}