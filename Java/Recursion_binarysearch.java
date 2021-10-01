public class Recursion_binarysearch{

    public static void main(String []args){
      int[] a={1,4,5,7,8,9};
      int x=bs(a,4,0,a.length-1);
      System.out.println(x);
    }
    public static int bs(int[] arr,int target,int start,int end){
        if(start>end){return -1;}
        int mid=start+(end-start)/2;
        if(target>arr[mid]){return bs(arr,target,mid+1, end);}
        else if(target==arr[mid]){return mid;}
        else{return bs(arr,target,start,mid-1);}
   }
}