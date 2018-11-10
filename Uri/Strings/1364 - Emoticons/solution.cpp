#include <bits/stdc++.h>
using namespace std;

struct trie{
	map<char, trie> m;
	bool end;
	trie(){ end = false;}
	void add(const string &s, int p=0){
		if(s.size()>p)
			m[s[p]].add(s, p+1);
		else
			end = true;
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int n, m;
	while(cin >> n >> m, n || m){
		long long ans = 0;
		trie t;
	 	for(int i=0; i<n; i++){
	 	 	cin >> s;
			t.add(s);
		}
		cin.ignore();
		for(int i=0; i<m; i++){
			string s1;
		        getline(cin, s1);
			//cout << s << '\n';
			unordered_map<int, trie*> aux;
			int j=0;
			set<int> borrar;
			for(char to: s1){	
				for(unordered_map<int, trie*>::iterator it = aux.begin(); it != aux.end(); it++){
				 	if(it->second->m.count(to) == 1){
						it->second = &(it->second->m[to]);
					}else{
						borrar.insert(it->first);
					}
				}
				for(auto it: borrar){
					aux.erase(it);
				}
				borrar.clear();
				if(t.m.count(to)==1){
					aux[j++] = &(t.m[to]);
				}
			 	for(auto it: aux){
					if(it.second->end){
						ans++;
						aux.clear();
						j=0;
						break;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}