import java.util.*;
class mergesort {
    static int ar[]=new int[10];
    public void merge(int a[],int b,int e){
        int mid;
        if(b<e){
            mid=(b+e)/2;
            merge(a,b,mid);
            merge(a,mid+1,e);
            sort(a,b,mid,e);
        }
    }
    public void sort(int ar[],int b,int mid,int e){
        int n1=mid-b+1;
        int n2=e-mid;
        int l[]=new int[n1];
        int r[]=new int[n2];
        for(int i=0;i<n1;i++){
            l[i]=ar[b+i];
        }
        for(int j=0;j<n2;j++){
            r[j]=ar[mid+1+j];
        }
        int i=0,j=0;
        int k = b;
        while (i < n1 && j < n2) {
            if (l[i] <= r[j]) {
                ar[k] = l[i];
                i++;
            }
            else {
                ar[k] = r[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            ar[k] = l[i];
            i++;
            k++;
        }
        while (j < n2) {
            ar[k] = r[j];
            j++;
            k++;
        }
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array:");
        int n=sc.nextInt();
        System.out.println("Enter the elements:");
        for(int i=0;i<n;i++){
            ar[i]= sc.nextInt();
        }
        System.out.println("Original Array:");
        for(int i=0;i<n;i++){
            System.out.print(ar[i]+" ");
        }
        mergesort ob = new mergesort();
        ob.merge(ar,0,n-1);
        System.out.println();
        System.out.println("Sorted Array:");
        for(int i=0;i<n;i++){
            System.out.print(ar[i]+" ");
        }
    }
}
