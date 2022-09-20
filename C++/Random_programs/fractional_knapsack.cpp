// Profits : float
// weights : int
#include<iostream>
using namespace std;

struct item
{
	float profit;
	int weight;
	float pbyw;
};

float knapsack(item I[], int n, int total_weight)
{
	for(int i = 0; i < n; i++)
		I[i].pbyw = (I[i].profit / I[i].weight);

	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - i - 1; j++)
			if(I[j].pbyw < I[j + 1].pbyw)
			{
				item temp = I[j];
				I[j] = I[j + 1];
				I[j + 1] = temp;
			} 

	/*for(int i = 0; i < n; i++)
		cout<<I[i].pbyw<<" ";
	cout<<endl;*/

	int used_weight = 0;
	float profit = 0;
	for(int i = 0; i < n; i++)
		if(used_weight + I[i].weight <= total_weight)
		{
			used_weight += I[i].weight;
			profit += I[i].profit;
		}
		else
		{
			int weight_left = total_weight - used_weight;
			profit += (I[i].pbyw * weight_left);
			break;
		}
	return profit;

}

int main()
{
	int n, total_weight;
	cout<<"Enter number of items : ";
	cin>>n;

	item I[n];
	cout<<"Enter profit and weight per item : "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"Profit["<<i<<"] : ";
		cin>>I[i].profit;
		cout<<"Weight["<<i<<"] : ";
		cin>>I[i].weight;
	}
	cout<<endl;

	cout<<"Enter maximim weight : ";
	cin>>total_weight;

	cout<<endl<<"Max profit : "<<knapsack(I, n, total_weight)<<endl;
	return 0;
}
/*
Output : 
Enter number of items : 3 
Enter profit and weight per item : 
Profit[0] : 25
Weight[0] : 18
Profit[1] : 24
Weight[1] : 15
Profit[2] : 15
Weight[2] : 10

Enter maximim weight : 20

Max profit : 31.5
*/