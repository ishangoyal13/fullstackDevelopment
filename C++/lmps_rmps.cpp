#include <iostream>
#include <vector>

using namespace std;


int lmps(int n,vector <int> v,int l)
{
    int i,sum=v[l-1],max=sum,pos=l-1;
    for ( i=l-1+1;i<n;i++)
    {
        sum+=v[i];
        if(sum>max)
        {
            max=sum;
            pos=i;
        }
    }
    return pos;
}

int rmps(int n,vector <int> v,int r)
{
    // ris value from back 
    
    int i,sum=v[r-1],max=sum,pos=r-1;
    for ( i=r-1;i>=0;i--)
    {
        sum+=v[i];
        if(sum>max)
        {
            //1,3,6,10,15,21
            //cout<<"rmps:"<<sum<<endl;

            max=sum;
            pos=i;
        }
    }
    return pos;
}


int main()
{
    vector <int> v;
    int i,n,k,l,r;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>k;
        v.insert(v.begin(),k);
    }

    cout<<"enter l and r: "<<endl;
    cin>>l;
    cin>>r;
    //cout<<l<<"\n"<<r<<endl;
    int LMPS=lmps(n,v,l);
    int RMPS=rmps(n,v,r);
    cout<<"LMPS is = "<<LMPS+1<<endl;
    cout<<"RMPS is = "<<RMPS+1<<endl;
    cout<<"MPS is i= "<<LMPS<<"j= "<<RMPS<<endl;
}

