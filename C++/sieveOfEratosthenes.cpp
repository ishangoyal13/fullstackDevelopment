/*
An older algorithm used to determine the prime numbers upto a given limit.

First assume that all the numbers from 2 to the given limit are prime numbers.
Then from 2 to limit/2, if the number is marked as prime, mark its multiples as 'not prime' up to the given limit.
The reason for choosing 'limit/2' for the upper for loop is because A multiple of a given number i is greater or equal to i * 2.
So the haflway number within the limit will always satisfy this condition.

Time Complexity - O(nlog(n))

    for i -> 2, limit / 2
        if i is a prime
            for j -> i * 2, limit + i   
                i is not a prime

    consider the second loop. If we start from 2 and go up to the limit with a step i everytime, then we can definetely say
    that the limit can be divided by 'i' steps.

    for the first step -> limit / 2, because we have gone for 2 multiples by then.
    for the second step -> limit / 3,
    for the third step -> limi / 5 (because 4 is already counted out as a multiple of 2)
    and so on..

    therefore total -> limit(1/2 + 1/3 + 1/5 + ... + 1 / (limit / 2)) 
                    <= limit(1/2 + 1/3 + 1/4 + ... + 1/ limit)
                    <= log(limit)

    Therefore by taking the upper bound, time complexity for the second for loop will be of log(n)
    hence the total complexity -> O(n log(n))

*/

#include <iostream>
using namespace std;

const int NMAX = 100001;
bool isPrime[NMAX];

void seiveOfEratosthenes(int n)
{
    for(int i = 2; i <= n; i++)
    {
        isPrime[i] = true;
        cout << i<<"-"<<isPrime[i] << " ";
    }

    cout << endl;

    for(int i = 0; i <= n / 2; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j = i * 2; j <= n; j += i)
            {
                isPrime[j] = false;
                cout << j << "fac" << " ";
                
            }
            cout << endl;
        }
        //cout << i << "-" << isPrime[i] << ". ";
    }
    cout << endl;
    //isPrime[4] = false;
}

int main()
{
    int n,count = 0;
    cin >> n;

    seiveOfEratosthenes(n);

    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i] == true)
        {
            cout << i << " " << isPrime[i] << endl;
            
        }
    }
    return 0;
}