using namespace std;
#include <bits/stdc++.h>

string deck;
string str;

bool evaluate(){
	return deck.find("11111")!=std::string::npos;
}
bool process(){
	if((str[1]==str[4])&&(str[4]==str[7])&&(str[7]==str[10])){
		for(int i=0;i<13;i+=3){
			if(str[i]<58&&str[i]>49)   deck[str[i]-48]='1';
			else if(str[i]=='A') 	 { deck[1]='1'; deck[14]='1';}
			else if(str[i]=='T')	   deck[10]='1';
			else if(str[i]=='J')	   deck[11]='1';
			else if(str[i]=='Q')	   deck[12]='1';
			else if(str[i]=='K')	   deck[13]='1';
		}
		//cout<<deck<<"\n";
		return evaluate();
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	while(getline(cin,str)){
 		deck="000000000000000";
 		if(process()) cout<<"YES\n";
 		else cout<<"NO\n";
 	}
	return 0;
}