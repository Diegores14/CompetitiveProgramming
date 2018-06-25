#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int n;
	string s;
	cin >> n;
	while(n--){
	 	cin >> s;
		int res=0;
		for(int i=0; i<(int)s.size(); i++){
		 	if(s[i]=='0'){res+=6;continue;}
			if(s[i]=='1'){res+=2;continue;}
			if(s[i]=='2'){res+=5;continue;}
			if(s[i]=='3'){res+=5;continue;}
			if(s[i]=='4'){res+=4;continue;}
			if(s[i]=='5'){res+=5;continue;}
			if(s[i]=='6'){res+=6;continue;}
			if(s[i]=='7'){res+=3;continue;}
			if(s[i]=='8'){res+=7;continue;}
			if(s[i]=='9'){res+=6;continue;}
		}
		cout << res << " leds\n";
	}

}