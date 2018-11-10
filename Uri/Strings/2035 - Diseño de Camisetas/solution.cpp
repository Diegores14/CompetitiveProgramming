#include <bits/stdc++.h>
using namespace std;

struct trie{
	map<char,trie> m;
	int frec;
	trie(){frec=0;}
	void add(string s,int dx, int p=0){
		frec += dx;
	 	if(s.size()>p)
			m[s[p]].add(s, dx, p+1);
	}
	long long dfs(){
		long long ans=0;
		for(auto &i: m){
		 	ans += i.second.dfs();
		}
		return ans + abs(frec);
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;
	while(cin >> n, n != -1){
		long long ans = 0;
		trie t;
	 	for(int i=0; i<n; i++){
			cin >> s;
			ans += s.size();
			t.add(s, 1);
		}
		for(int i=0; i<n; i++){
			cin >> s;     
			ans += s.size();  
			t.add(s, -1);
		}
		cout << ((ans - t.dfs())>>1) << '\n';
	}
}