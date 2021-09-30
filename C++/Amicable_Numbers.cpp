#include<iostream>
using namespace std;

int main(){
    int num1;
    int num2;
    int sum1=0;
    int sum2=0;
    cout<<"Enter first number";
    cin>>num1;
    cout<<"Enter second number";
    cin>>num2;
    for(int i=1;i<num1;i++){
        if(num1%i==0){
            sum1 = sum1+i;
        }
        else{
            continue;
        }
    }
    for(int j=1;j<num2;j++){
        if(num2%j==0){
            sum2 = sum2+j;
        }
        else{
            continue;
        }
    }
    /*cout<<sum1<<endl;
    cout<<sum2<<endl;*/
    if(sum1==num2 && sum2==num1){
        cout<<"Amicable Number";
    }
    else{
        cout<<"Not Amicable Number";
    }

    return 0;

}
