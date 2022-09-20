public class TOH
{
    // a recursive java program to solve tower of hanoi
    static void towerOfHanoi(int n, char f_rod, char t_rod, char a_rod)
    {
        if (n == 1)
        {
            System.out.println("Move disk 1 from rod " +  f_rod + " to rod " + t_rod);
            return;
        }
        towerOfHanoi(n-1, f_rod, a_rod, t_rod);
        System.out.println("Move disk " + n + " from rod " +  f_rod + " to rod " + t_rod);
        towerOfHanoi(n-1, a_rod, t_rod, f_rod); //calling the function itself, hence recursive
    }
    //  Driver method
    public static void main(String args[])
    {
        int n = 4; // Number of disks
        towerOfHanoi(n, 'A', 'C', 'B');// A,B,C are the name of the rods
    }
}