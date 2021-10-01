// Count Sort //

import java.util.*;

class code {

    // Sorting Method //
    public static int[] cSort(int[] arr, int n) {
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            max = Math.max(arr[i], max);
        }
        int[] count_arr = new int[max + 1];
        for (int i = 0; i < n; i++) {
            count_arr[arr[i]] = count_arr[arr[i]] + 1;
        }
        for (int i = 1; i < max + 1; i++) {
            count_arr[i] += count_arr[i - 1];
        }
        int[] result = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            count_arr[arr[i]]--;
            result[count_arr[arr[i]]] = arr[i];
        }
        return result;
    }

    // Driver Function //
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];

        // Inputing the Array
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        // Sorting
        arr = code.cSort(arr, n); // Creating an object of the class

        // Printing the Array
        System.out.println("New Array: ");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}