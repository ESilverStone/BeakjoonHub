import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	
	public static int cal(PriorityQueue<Integer> que, Map<Integer, Integer> map) {
		
		int num;
		
		while(true) {
			num = que.poll();

			int cnt = map.getOrDefault(num, 0);
			
			if(cnt == 0) continue;		// 해당 num이 이미 삭제된 경우
			
			else if(cnt == 1) {			// 중복없이 ㄹㅇ 하나만
				map.remove(num);
				
			} else {					// 중복인 경우
				map.put(num, cnt-1);
				
			}
			break;
		}
		return num;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int T = Integer.parseInt(br.readLine());
		
		for(int t=0; t<T; t++) {
			int N = Integer.parseInt(br.readLine());
			
			// map
			Map<Integer, Integer> map = new HashMap<>();
			
			// 큰거 제거하는 큐
			PriorityQueue<Integer> lque = new PriorityQueue<>(Collections.reverseOrder());
			// 작은거 제거하는 큐
			PriorityQueue<Integer> sque = new PriorityQueue<>();
							
			
			for(int i=0; i<N; i++) {
				String[] input = br.readLine().split(" ");
					
				char ch = input[0].charAt(0);
				int num = Integer.parseInt(input[1]);
				
				
				if(ch=='I') {					// 입력
					lque.add(num);
					sque.add(num);
					
					// num인 key가 없으면 기본값 0+1이 들어가고
					// 있으면 value에 1 더한 값이 들어간다. 
					map.put(num, map.getOrDefault(num, 0)+1);
					
				} else {								// 삭제
					if(map.isEmpty()) continue;
					
					if(num == 1) {						// 큰거 삭제
						cal(lque, map);
						
					} else {							// 작은거 삭제
						cal(sque, map);
					}
				}
			}
			if(map.isEmpty())
				System.out.println("EMPTY");
			else {
				long result = cal(lque, map);
				long result2 = (map.isEmpty()) ? result : cal(sque, map); 
				System.out.println(result+" "+result2);
			}	
		}
	}
}