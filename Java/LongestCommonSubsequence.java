/*

By Krish Jani (KrishJani)

tails is an array storing the smallest tail of all increasing subsequences with length i+1 in tails[i].
For example, say we have nums = [4,5,6,3], then all the available increasing subsequences are:

len = 1   :      [4], [5], [6], [3]   => tails[0] = 3
len = 2   :      [4, 5], [5, 6]       => tails[1] = 5
len = 3   :      [4, 5, 6]            => tails[2] = 6
We can easily prove that tails is a increasing array. Therefore it is possible to do a binary search in tails array to find the one needs update.

Each time we only do one of the two:

(1) if x is larger than all tails, append it, increase the size by 1
(2) if tails[i-1] < x <= tails[i], update tails[i]
Doing so will maintain the tails invariant. The the final answer is just the size.

*/

Class HacktoberFest{

    public int lengthOfLIS(int[] nums) {
        int[] tails = new int[nums.length];
        int size = 0;
        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if (i == size) ++size;
        }
        return size;
    }

}
// Runtime: 2 ms
    public static void main(String args[])
    {
        HacktoberFest ob = new HacktoberFest();
        int A[] = {31, 21, 101, 41, 401};
        int n = arr.length;
        int x = 4;
        int result = ob.binarySearch(arr, 0, n - 1, x);
        if(result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element present at index " +
                                result);
    }
}