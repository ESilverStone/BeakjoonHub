import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
	
		
		// 긴 문자열을 받는다.
		char[] arr = sc.next().toCharArray();
		
		// 0번 부터 arr.length-1까지 스택에 후위연산자로 넣는다.
		// 1. 피연산자면 그냥 출력 > 다른 배열에 보관
		// 2. 연산자면 스택으로 먼가를 하는데..
		// 2-1. 스택에 아무 것도 업다. > 연산자 넣기
		// 2-2. 다음 연산자 차례가 오면 스택 맨위에 있는 연산자와 비교한다.
		// 2-2-1. 전에 있는 연산자가 더 빠르다. 그거 빼고 다음거 비교
		// 2-2-2. 다음 연산자가 더 빠르다. 그럼 그냥 넣기
		// 3. 괄호가 있는 경우
		// 3-1. '(' 괄호가 방파제 역할을 한다.
		// 3-2. 그러다 ')' 괄호가 나오는 순간 ( ) 사이에 있는 값을 스택에서 빼낸다.
		// 빠른 순서 ^, *, /, +, -
		
		char[] arr2 = new char[arr.length];
		int n=0;
		Stack<Character> st = new Stack<>();
		
		for(int i=0; i<arr.length; i++) {
			// 숫자면 배열arr2에 보관
			if('A'<=arr[i] && arr[i]<='Z') arr2[n++] = arr[i];
		
			// +의 경우
			else if (arr[i] == '+' || arr[i] == '-') { 
				// 비어 있으면 그냥 넣기
				if(st.isEmpty()) st.push(arr[i]);
				
				// 막 들어온 +은 최약체이므로 끝까지 또는 (를 만날 때까지 다 비운다.
				//else if(st.peek() == '+' || st.peek() == '*'){
				else {
					while(!st.isEmpty() && !(st.peek()=='('))
						arr2[n++] = st.pop();	
			
					st.push(arr[i]); // 다 비우고 들어온 +만 보관
				}
			} 
			
			// *인 경우  
			else if(arr[i] == '*' || arr[i] == '/'){ 
				// 비어 있으면 그냥 넣기
				if(st.isEmpty() || st.peek()=='(') st.push(arr[i]);

				// *의 경우 그 전과 비교를 해준다.
				else if(st.peek() == '+' || st.peek() == '-') 	 // 비교 대상이 +인 경우
					st.push(arr[i]);
				
				else if(st.peek() == '*' || st.peek() == '/') {	 // 비교 대상이 *인 경우
					arr2[n++] = st.pop();
					st.push(arr[i]);
				}
			} 
			
			// (인 경우
			else if(arr[i] == '(') {			
				st.push(arr[i]); 			 // ( 괄호는 무조건 스택에 쌓기만 한다. 그리고 )가 올 때까지 기다린다.
			} 
			
			// )인 경우
			else if(arr[i] == ')') {		
				while(!(st.peek() =='(')) 		 
					arr2[n++] = st.pop();    // ( 을 찾을 때까지 스택을 다 빼낸 후 배열에 넣는다.
				
				st.pop();					 // '('도 제거해준다.
			}
		}
		// 남아 있는거 다 배출
		while(!st.isEmpty()) {
			arr2[n++] = st.pop();		
		}
			
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<n; i++) {
			sb.append(arr2[i]);
		}
		System.out.println(sb);
		
	}
}