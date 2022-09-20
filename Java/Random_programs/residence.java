import java.util.Scanner;

public class residence {
    String resi_name;
    String block;
    int flat_no;
    int due_amount;
    String mobile;

    public static void menu(){
        System.out.println("Options Menu");
        System.out.println("---------------");
        System.out.println("1. Know the due amount");
        System.out.println("2. Pay the maintenance");
        System.out.println("3. Add new resident details");
        System.out.println("4. Delete the existing residence");
        System.out.println("0 to exit");
        System.out.println("----------------------");
    }

    public void get()
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter residence name : ");
        resi_name = sc.nextLine();
        System.out.println("Enter block : ");
        block = sc.nextLine();
        System.out.println("Enter flat number : ");
        flat_no = sc.nextInt();
        System.out.println("Enter due amount : ");
        due_amount = sc.nextInt();
        System.out.println("Enter mobile number : ");
        mobile = sc.next();
    }

    public void print()
    {
        System.out.println("Residence name : " + resi_name);
        System.out.println("Block : " + block);
        System.out.println("Flat Number : " + flat_no);
        System.out.println("Due amount : " + due_amount);
    }

    public void pay()
    {
        Scanner sc= new Scanner(System.in);
        if (due_amount == 0)
        {
            System.out.println("The due amount is paid");
        }
        else if (due_amount > 0)
        {
            int amt;
            System.out.println("Enter amount : ");
            amt = sc.nextInt();
            due_amount -= amt;
            if (due_amount == 0)
            {
                System.out.println("The due amount is paid");
            }
            if (due_amount < 0)
            {
                System.out.println("Your due is paid , the extra amount is " + -(due_amount));
            }
        }
    }

    public static void main(String args[])
    {
        int flag = 400;
        Scanner sc = new Scanner(System.in);
        residence cus[] = new residence[30];
        System.out.println("Enter number of residents :");
        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            cus[i] = new residence();
            System.out.println("Enter details \n --------------\n");
            cus[i].get();
        }
        menu();
        while (flag != 0)
        {
            int res,b;
            System.out.println("Enter Option : ");
            flag = sc.nextInt();
            if (flag == 0){
                break;
            }
            System.out.println("Enter flat number : ");
            b = sc.nextInt();
            if (flag == 1){
                for (int i = 0 ; i < N ; i++)
                {
                    if (cus[i].flat_no == b)
                    {
                        cus[i].print();
                    }
                }
            }
            if (flag == 2){
                for (int i = 0 ; i < N ; i++)
                {
                    if (cus[i].flat_no == b)
                    {
                        cus[i].pay();
                    }
                }
            }

        }

    }

}
