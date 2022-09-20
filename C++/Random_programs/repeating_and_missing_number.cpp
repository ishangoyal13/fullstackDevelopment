#include <iostream>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--) //test cases
	{
	    int N;
	    cin>>N;
	    //Input all N eleemnts
        int arr[N];
        int repeating,missing;
        bool present[N+1] = {false};  //Checks which numbers are present
        for(int i=0;i<N;++i)
        {
            cin>>arr[i];
            if(present[arr[i]]==true)
                repeating = arr[i];
            present[arr[i]] = true;
        }

        for(int i=1;i<=N;++i)
        {
            if(present[i]==false)
            {
                missing = i;
                break;
            }
        }

        cout<<repeating<<" "<<missing<<"\n";
	}
	return 0;
}
