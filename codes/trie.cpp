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