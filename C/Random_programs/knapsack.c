#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    float weight[n];
    for (int i=0;i<n;i++)
    {
        scanf("%f",&weight[i]);
    }
    
    float profit[n];
    for(int i=0;i<n;i++)
    {
        scanf("%f",&profit[i]);
    }
    
    float cpty;
    scanf("%f",&cpty);
    
    float r[n];
    for (int i=0;i<n;i++)
    {
        r[i]=profit[i]/weight[i];
    }
    
    float arr[n];
    int temp;
    for (int i=0;i<n-1;i++)
    {
        arr[i]=0;
        temp=i;
        for(int j=i+1;j<n;j++)
        {
            if(r[j]>r[temp])
            {
                temp=j;
            }
        }
        if(temp!=i)
        {
            r[i]=r[i]+r[temp];
            r[temp]=r[i]-r[temp];
            r[i]=r[i]-r[temp];
            
            weight[i]=weight[i]+weight[temp];
            weight[temp]=weight[i]-weight[temp];
            weight[i]=weight[i]-weight[temp];
            
            profit[i]=profit[i]+profit[temp];
            profit[temp]=profit[i]-profit[temp];
            profit[i]=profit[i]-profit[temp];
        }
    }
    
    float w=0;
    arr[n-1]=0;
    for(int i=0;i<n;i++)
    {
        if(w+weight[i]<=cpty)
        {
            arr[i]=1;
            w+=weight[i];
        }
        else
        {
            arr[i]=(cpty-w)/weight[i];
            w=cpty;
            break;
        }
    }
    
    float tProfit=0;
    for(int i=0;i<n;i++)
    {
        tProfit+=arr[i]*profit[i];
    }
    
    printf("%.2f",tProfit);
    return 0;
}