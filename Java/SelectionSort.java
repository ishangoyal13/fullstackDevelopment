public class SelectionSort {
    public static void main(String[] args) {
        int[] arr ={38,52,9,18,6,62,13};
        selectionSort(arr);
        for (int i:arr) {
            System.out.print(i+" ");
        }
    }

    static void selectionSort(int[] arr){
        int min, temp;
        for (int i = 0; i < arr.length; i++) {
            min=i;
            for (int j = i+1; j < arr.length; j++) {
                if(arr[j]<arr[min]) min=j;
            }
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}
