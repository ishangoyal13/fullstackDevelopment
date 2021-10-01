package sorting_algo;

import java.util.Scanner;

public class BubbleSortAlgo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int a[] = new int[n];
		
		for(int i=0; i<n; i++) {
			a[i]=sc.nextInt();
		}
		
		for(int i=0; i<n-1; i++) {
			for(int j=0; j<n-1; j++) {
				if(a[j+1]<a[j]) {
					int temp = a[j+1];
					a[j+1] = a[j];
					a[j]= temp;
				}
			}
		}
		
		for(int e:a) {
			System.out.print(e+" ");
		}
		
	}
}
