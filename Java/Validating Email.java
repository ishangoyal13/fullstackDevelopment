import java.util.Scanner;
// Other imports go here
// Do NOT change the class name
class Main
{
  public static void main(String[] args)
  {
    String id;
    Scanner s1=new Scanner(System.in);
    id=s1.nextLine();
    int flag=0;
    int l=id.length();
    try
    {
    for(int i=0;i<l;i++)
    {
      if(id.charAt(i)=='@')
      {
        for(int j=i+1;j<l;j++)
        {
          if(id.charAt(j)=='.')
          {flag=1;
          break;}
        }
      }
    }
    if(flag==1)
    {System.out.println("Valid");}
    else
    {throw new Exception("Invalid");}
    }
  catch(Exception e)
  {
    System.out.println(e.getMessage());
  }
  }
}