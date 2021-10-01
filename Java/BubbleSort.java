public class BubbleSort {
    public static void main(String[] args) {
        int[] arr = {95,9,45,12,74,56,54,41};

        bubbleSort(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    static void bubbleSort(int[] arr){
        for (int i = 0; i < arr.length-1; i++) {
            int flag=0,temp;
            for (int j = 0; j < arr.length-1-i; j++) {
                if (arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    flag=1;
                }
            }
            if (flag==0) break;
        }
    }
}
