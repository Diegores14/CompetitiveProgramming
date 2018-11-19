#include <bits/stdc++.h>
using namespace std;

struct trie{
	bool end;
	map<char, trie> m;
	trie(){end = false;}
	void add(string s, int p=0){
		if(p<s.size())
			m[s[p]].add(s,p+1);
		else
			end = true;
	}
	long long dfs(const int & n, int p=0){
		long long ans = 0;
		if(end){return ((long long)1<<(n-p));}
	 	 for(auto i: m){
		  	ans += i.second.dfs(n, p+1);
	 	 }
	 	 return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, p;
	string s;
	cin >> t;
	for(int k=1; k <= t; k++){
		cout << "Case #" << k << ": ";
		cin >> n >> p;
		trie tri;
		long long ans = ((long long)1<<n);
		for(int i=0; i<p; i++){
		 	cin >> s;
		 	tri.add(s);
		}
		cout << ans - tri.dfs(n) << '\n';
	}

	return 0;
}