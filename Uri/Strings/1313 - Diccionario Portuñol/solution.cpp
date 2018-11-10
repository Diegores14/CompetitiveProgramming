#include <bits/stdc++.h>
using namespace std;

long long quitar = 0;

struct trie{
	map<char,trie> m;
	int frec;
	bool init;
	trie(bool i=false){frec=0; init = i;}
	void add1(const string &s, int p=0){		
	 	if((int)s.size()>p){
			m[s[p]].add1(s, p+1);
		}
	}
	void add2(const string &s, int p){		
	 	if(p>=0){
			m[s[p]].add2(s, p-1);
		}
	}

	int dfs1(const vector<int> & v){
		int sum = 0;
	 	for(auto &to : m){
			if(!init)
				quitar += v[to.first-'a'];
			sum += to.second.dfs1(v);
		}
		return sum + 1;
	}

	int dfs2(vector<int> & v){
		int sum = 0;		
	 	for(auto &to : m){
			if(!init)
				v[to.first-'a']++;
			sum += to.second.dfs2(v);
		}
		return sum + 1;
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int p, s;
	string s1;
	while(cin >> p >> s, p || s){
		quitar = 0;
	 	vector<int> rest(26,0);
		long long ans = 0;
		trie portu(true), spanish(true);
		for(int i=0; i<p; i++){
			cin >> s1;
			portu.add1(s1);
		}
		for(int i=0; i<s; i++){
			cin >> s1;
			spanish.add2(s1, s1.size()-1);
		}
		ans = spanish.dfs2(rest)-1;
		ans *= portu.dfs1(rest)-1;
		cout << ans - quitar << '\n';
	}
	return 0;
}