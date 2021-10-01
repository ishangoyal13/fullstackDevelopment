package Stack;

import java.util.Stack;

public class NextGreaterElement {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] arr = {2, 1, 3, 7, 5, 8};
		Stack<Integer> stack = new Stack<>();
		
		for(int i =0 ; i<arr.length; i++) {
			while(!stack.isEmpty() && arr[i]>stack.peek()) {
				int rv = stack.pop();
				System.out.println(rv + "-->" + arr[i]);
			}
			stack.push(arr[i]);
		}
		while(!stack.isEmpty()) {
			int rv = stack.pop();
			System.out.println(rv+"-->"+"-1");
		}

	}

}
