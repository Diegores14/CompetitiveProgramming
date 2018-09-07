#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int ans=0;
	 	vector<vector<int>> v(26, vector<int>());
	 	string s;
	 	cin >> s;
	 	for(int i=0; i<(int)s.size(); i++)v[s[i]-'A'].emplace_back(i);
	 	if(s.size()>=3)  
	 	for(int i=0; i<26; i++){              
	 		vector<int>::iterator it = upper_bound(v[i].begin(), v[i].end(),-1);
	 		if(it!=v[i].end())
	 	 	for(int j=0; j<26; j++){              
				vector<int>::iterator it1 = upper_bound(v[j].begin(), v[j].end(), *it);
	 			if(it1!=v[j].end())
	 	 	 	for(int k=0; k<26; k++){              
	 	 	 	 	vector<int>::iterator it2 = upper_bound(v[k].begin(), v[k].end(), *it1);
	 				if(it2!=v[k].end())ans++;
	 	 	 	}      
	 	 	}      
	 	}
	 	cout << ans << '\n';
	}
 	return 0;
}