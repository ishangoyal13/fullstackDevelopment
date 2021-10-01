// Calculate the lenght of longest Common substring
//Solution:
public class LongestCommonSubstring{

    public static void main(String []args){
       String a = "abcdxyz";
       String b = "xyzabcd";
       int i,j;
       int lena = a.length();
       int lenb = b.length();
       int[][] arr = new int[lena+ 1][lenb+1];
       
       for(i = 0; i<= lena; i++ )
       {
           for(j = 0;j<=lenb; j++)
           {
               if(i==0 || j==0)
               arr[i][j] = 0;
           }
       }
       for(i = 1; i<= lena; i++ )
       {
           for(j = 1;j<=lenb; j++)
           {
               if(a.charAt(i-1) == b.charAt(j-1))
               {
                   arr[i][j] = 1 + arr[i-1][j-1];
               }
               else
               arr[i][j] = 0;
           }
       }    
       int max =0;
       for(i = 0; i<= lena; i++ )
       {
           for(j = 0;j<=lenb; j++)
           {

                    if(arr[i][j]>max)
                    {
                        max = arr[i][j];
                    }
           }
       }
       
       
       System.out.println("Longest Common Substring : "+max+" length");
   }
}