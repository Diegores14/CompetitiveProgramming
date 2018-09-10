#include <bits/stdc++.h>
using namespace std;
long long cont;

struct trie{
	map<char,trie> m;
	int end, frec;
	trie(){end=0; frec=0;}
	void add(const string &s, int p=0){		
	 	if((int)s.size()>p) m[s[p]].add(s, p+1);
		else{ end = 1; frec++;}
	}
	void dfs(int carry){
		int sum = ((int)m.size()>1 || end);
	 	for(auto &to : m)
			to.second.dfs(carry+sum);
		if(end){cont+=frec*carry;}
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cout << fixed << setprecision(2);
	while(cin >> n){
	 	trie t;
		string aux;
		cont = 0;
		for(int i=0; i<n; i++){
			cin >> aux;
			t.add(aux);
		}
		t.dfs(t.m.size()==1);
		cout << (double)cont/n << '\n';
	}
        return 0;
}	