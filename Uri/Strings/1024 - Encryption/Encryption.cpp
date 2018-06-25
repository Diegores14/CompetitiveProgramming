#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int N;
	char s[1003];
	cin >> N;
	cin.ignore();
	while(N--){	
	 	cin.getline(s, 1003);
		int i;
		for(i=0; s[i]!='\0'; i++)if(('a'<=s[i]&&s[i]<='z') || ('A'<=s[i]&&s[i]<='Z'))s[i]+=3;
		reverse(s, s+i);
		for(int j=i/2; s[j]!='\0'; j++)s[j]-=1;
		cout << s << '\n';
	}
 	return 0;
}