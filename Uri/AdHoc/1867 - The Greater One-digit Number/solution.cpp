#include <bits/stdc++.h>
using namespace std;

string onedigit(string s){
	long long n=0;
 	for(char to : s)n+=(to-'0');
 	return to_string(n);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s1, s2;
	while(cin >> s1 >> s2, s1!="0" || s2!="0"){
	 	 while(s1.size()!=1){ s1=onedigit(s1);}
	 	 while(s2.size()!=1){ s2=onedigit(s2);}
	 	 int a = atoi(s1.c_str()),
	 	 b = atoi(s2.c_str());
	 	 if(a==b) cout << "0\n";
	 	 if(a>b) cout << "1\n";
	 	 if(a<b) cout << "2\n";
	}
	return 0;
}