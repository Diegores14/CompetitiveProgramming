#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> frec(1000005, 0);
long long total=0;

void add(int idx){
	total -= (long long)frec[v[idx]]*frec[v[idx]]*v[idx];
	frec[v[idx]]++;
	total += (long long)frec[v[idx]]*frec[v[idx]]*v[idx];
}

void remv(int idx){
	total -= (long long)frec[v[idx]]*frec[v[idx]]*v[idx];
	frec[v[idx]]--;
	total += (long long)frec[v[idx]]*frec[v[idx]]*v[idx];
}

long long getAnswer(){
	return total;
}

int blockSize;

struct Query{
	int l, r, idx;
	bool operator <(Query other)const
	{
	 	if(l / blockSize != other.l / blockSize)
			return l < other.l;
		else
			return ((l / blockSize) & 1)? (r > other.r) : (r < other.r);
	}
};

void mo_s_algorithm(vector<Query> & queries){
	vector<long long> answer(queries.size());
	sort(queries.begin(), queries.end());
	
	int l=0, r=-1;
	for(Query it : queries){
	 	while(l < it.l){
	 	 	remv(l);
			l++;
		}
		while(r < it.r){
			r++;
	 	 	add(r);
		}
		while(l > it.l){
			l--;
	 	 	add(l);			
		}
		while(r > it.r){
	 	 	remv(r);
			r--;
		}
		answer[it.idx] = getAnswer(); 
	}
	for(long long it : answer)
		cout << it << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, t;
	blockSize = ceil(sqrt(n));
	cin >> n >> t;
	v.assign(n, 0);
	for(auto &it: v)
		cin >> it;
	vector<Query> queries(t);
	for(int i=0; i<t; i++){
	 	cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].idx = i;
	}
	mo_s_algorithm(queries);
	return 0;
}