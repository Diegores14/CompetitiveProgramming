#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	string s;
	vector<int> v;
	while(getline(cin, s)){
	 	v.clear();
		v.push_back(0);
		bool aux=false;
		int res=0;
		for(int i=0; i < (int)s.size(); i++){
			if(s[i]==' ')v.push_back(i+1);
			if('A'<=s[i] && s[i] <= 'Z')s[i]+=32;
		}
		for(int i=1; i<(int)v.size(); i++){
			if(s[v[i-1]]==s[v[i]]&& !aux){res++;aux=true;}
			if(aux && s[v[i-1]]!=s[v[i]])aux=false;
		}
		cout << res << '\n'; 
	}

}