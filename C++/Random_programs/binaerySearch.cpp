#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val)
{
    for(int i=0;i<n;i++)
    {
        if(input[i]==val)
            return i;
        
    }
    return -1;
}
int main() {
    int size;
	cin >> size;
	int *input = new int[size];

	for(int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}
	
	int t;
	cin >> t;

	while (t--)
	{
		int val;
		cin >> val;
		cout << binarySearch(input, size, val) << endl;
	}
	
	delete [] input;
	return 0;
}