package com.company;
import java.util.Arrays;

public class Cyclic {

    public static void main(String[] args) {
        int[] arr = {5, 4, 3, 2, 1};
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void sort(int arr[]) {
        int a = 0;
        while (a < arr.length){
            int c = arr[a]-1;
            if (arr[a] != arr[c]){
                swap(arr , a, c);
            } else {
                a++;
            }
        }



    }
    static void swap(int[] arr, int first , int second) {
        int temp =arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
