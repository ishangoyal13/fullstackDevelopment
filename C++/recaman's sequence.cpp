// Cpp program to print n-th number in Recaman' sequence
#include <iostream>
#include <algorithm>
using namespace std;

int recaman(int n)
{

	int arr[n];

	arr[0] = 0;
	printf("%d, ", arr[0]);

	for (int i=1; i< n; i++)
	{
		int curr = arr[i-1] - i;
		int j;
		for (j = 0; j < i; j++)
		{
			if ((arr[j] == curr) || curr < 0)
			{
				curr = arr[i-1] + i;
				break;
			}
		}

		arr[i] = curr;
		printf("%d, ", arr[i]);
	}
	return 0;
}

// Driver code
int main()
{
	int n;
	cout<<"Enter the n-th number: ";
	cin>>n;
	recaman(n);
	return 0;
}
