// Required packages
import java.util.Stack;
import java.util.Scanner;

// Java program to get minimum element of stack in O(1) time complexity

// Class to perform basic functions on stack, with O(n) space complexity
class helper1 {

	// Auxilliary Stack to store minimum elements of stack
	Stack<Integer> auxStack = new Stack<>();

	// Basic functions on stack
	public void push(int a, Stack<Integer> s) {
		if(auxStack.isEmpty()) {
			auxStack.push(a);
		} else if(a <= auxStack.peek()) {
			auxStack.push(a);
		}
		s.push(a);
	}

	public int pop(Stack<Integer> s) {
		if(s.peek() == auxStack.peek()) {
			auxStack.pop();
		}
		int x = s.peek(); s.pop();
 		return x;
	}

	public int peek(Stack<Integer> s) {
		return s.peek();
	}

	// getMin() function to get minimum element in O(1) time
	public int getMin(Stack<Integer> s) {
		return auxStack.peek();
	}
}

// Class to perform basic functions on stack, with O(1) space complexity
class helper2 {

	// Variable to maintain minimum element in stack everytime
	int min = 0;

	// Basic stack operations
	public void push(int x, Stack<Integer> s) {
		if(s.isEmpty()) {
			s.push(x);
			min = x;
		} else if(x <= min) {
			s.push(2 * x - min);
			min = x;
		} else {
			s.push(x);
		}
	}

	public int peek(Stack<Integer> s) {
		int t = s.peek();
		return t <= min ? min : t;
	}

	public int pop(Stack<Integer> s) {
		int t = s.peek(); s.pop();
		if(t <= min) {
			int tmp = min;
			min = 2 * min - t;
			return tmp;
		} else {
			return t;
		}
	}

	// getMin() function to get minimum element in O(1) time
	public int getMin(Stack<Integer> s) {
		return min;
	}
}

public class get_minimum {
	public static void main(String[] args) {
		// Creating stack that will support getMin() function
		Stack<Integer> st = new Stack<>();

		helper1 hc1 = new helper1();

		hc1.push(5, st);
		hc1.push(10, st);
		hc1.push(20, st);
		hc1.push(2, st);
		hc1.push(6, st);
		hc1.push(4, st);
		System.out.println("Popped: " + hc1.pop(st));
		System.out.println("Popped: " + hc1.pop(st));
		System.out.println("Minimum element: " + hc1.getMin(st));
		hc1.push(2, st);
		System.out.println("Popped: " + hc1.pop(st));
		System.out.println("Minimum element: " + hc1.getMin(st));
		hc1.push(1, st);
		System.out.println("Popped: " + hc1.pop(st));
		System.out.println("Popped: " + hc1.pop(st));
		System.out.println("Minimum element: " + hc1.getMin(st));
		System.out.println("-----------------------------------");

		// To empty stack
		while(!st.isEmpty()) {
			st.pop();
		}

		helper2 hc2 = new helper2();

		hc2.push(5, st);
		hc2.push(10, st);
		hc2.push(20, st);
		hc2.push(2, st);
		hc2.push(6, st);
		hc2.push(4, st);
		System.out.println("Popped: " + hc2.pop(st));
		System.out.println("Popped: " + hc2.pop(st));
		System.out.println("Minimum element: " + hc2.getMin(st));
		hc2.push(2, st);
		System.out.println("Popped: " + hc2.pop(st));
		System.out.println("Minimum element: " + hc2.getMin(st));
		hc2.push(1, st);
		System.out.println("Popped: " + hc2.pop(st));
		System.out.println("Popped: " + hc2.pop(st));
		System.out.println("Minimum element: " + hc2.getMin(st));
	}
}