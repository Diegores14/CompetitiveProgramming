#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> frec(300005, 0);
set<int> ans, cercanos;
int blockSize;
int limite, limite2;

void add(int idx){
	frec[v[idx]]++;
	if(frec[v[idx]] > limite){
		ans.insert(v[idx]);
	}
	if(frec[v[idx]] > limite2){
		cercanos.insert(v[idx]);
	}
}

void remv(int idx){
	frec[v[idx]]--;
	if(frec[v[idx]] <= limite)
		ans.erase(v[idx]);
	if(frec[v[idx]] <= limite2)
		cercanos.erase(v[idx]);
}

int getAnswer(){
	if(ans.size()==0) return -1;
	set<int>::iterator it = ans.begin();
	return *it;
}

struct Query{
	int l, r, k, idx;
	bool operator <(Query other)const
	{
	 	if(l / blockSize != other.l / blockSize)
			return l < other.l;
		else
			return ((l / blockSize) & 1)? (r > other.r) : (r < other.r);
	}
};

void mo_s_algorithm(vector<Query> & queries){
	vector<int> answers(queries.size());
	sort(queries.begin(), queries.end());
	int l=0, r=-1;
	for(Query it: queries){
		limite =  (it.r - it.l + 1) / it.k;
		limite2 = (it.r - it.l + 1 - (blockSize<<1)) / it.k;
		vector<int> aux;
		for(int to : ans){
			if(frec[to] <= limite){
				aux.emplace_back(to);
			}
		}
		for(int to: aux)
			ans.erase(to);
		vector<int> aux1;
		for(int to : cercanos){
			if(frec[to] <= limite){
				aux.emplace_back(to);
			}
		}
		for(int to: aux)
			ans.erase(to);
	 	while(l < it.l){
	 	 	remv(l);
			l++;
		}
		while(r < it.r){
		 	add(++r);
		}
		while(l > it.l){
		 	add(--l);
		}
		while(r > it.r){
			remv(r);
			r--;
		}
		answers[it.idx] = getAnswer();
	}
	for(int it: answers)
		cout << it << '\n';
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	blockSize = ceil(sqrt(n));
	v.assign(n, 0);
	for(int &it: v){
		cin >> it;
	}
	vector<Query> queries(q);
	for(int i=0; i < q; i++){
		cin >> queries[i].l >> queries[i].r >> queries[i].k;
		queries[i].l--;
		queries[i].r--;
		queries[i].idx  = i;
	}
	mo_s_algorithm(queries);
	return 0;
}