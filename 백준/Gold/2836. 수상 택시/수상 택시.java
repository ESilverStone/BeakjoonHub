import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int depart = Integer.parseInt(st.nextToken());
		
		int[][] arr = new int[N][2];
				
		
		// 입력
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			// 거꾸로 담는다.
			arr[i][1] = Integer.parseInt(st.nextToken());
			arr[i][0] = Integer.parseInt(st.nextToken());
		}
		
		// 정렬
		Arrays.sort(arr, (e1, e2)->{
			return e1[0] - e2[0];
		});
		
		// 초기값
		int start = 0;
		int end = 0;
		
		long sum = 0;
		
		for(int i=0; i<N; i++) {
			
			int newS = arr[i][0];
			int newE = arr[i][1];
			
			// 역행일 경우
			if(newS < newE) {
				// 일단 새로운 시작점이 기존 끝보다 밖에 있는지 확인
				if(newS > end) {
					start = newS;
					end = newE;
					
					sum += (newE - newS);
				} 
				// 새로운 시작점이 안에 있는 경우
				else {
					// start는 그대로
					if(newE > end) {
						sum += newE - end;
						end = newE;
					}				
				}
			}
		}
		sum *= 2;
		sum += depart;
		System.out.println(sum);
	}
}