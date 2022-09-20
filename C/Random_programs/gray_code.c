#include <stdio.h>
#define DEBUG(x); printf("%d------\n",x);
#define ll long long
int power(int a,int b){
	int ans=1;
	for(int i=0;i<b;i++)ans*=a;
	return ans;
}
int main(){
	int n,len;
	printf("ENter the length for binary numbers\n");
	scanf("%d",&n);
	int end=power(2,n);
	for(int k=0;k<end;k++){
		int a[32]={0},num=k;
		len=0;
		while(num>0){
			a[len++]=num%2;
			num/=2;
		}
		
			for(int i=0;i<n-len;i++)printf("0");
		if(len!=0)printf("%d",a[len-1]);
		for(int i=len-1;i>0;i--){
			printf("%d",(a[i]+a[i-1])%2);
		}
		printf("\n");
	}
	return 0;
}