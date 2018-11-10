#include <bits/stdc++.h>
using namespace std;

vector<int> v;
long long total = 0;
vector<int> frec((1<<20), 0);
int k;

void remov(int idx){
	frec[v[idx]]--;
	total -= frec[v[idx]^k];
}

void add(int idx){
	total += frec[v[idx]^k];
	frec[v[idx]]++;	
}

long long get_answer(){
 	return total;
}

int block_size;



struct Query{
	int l, r, idx;
	bool operator<(Query other)const
	{
	 	if(l / block_size != other.l / block_size)
			return l < other.l;
		else
			return ((l / block_size) & 1)? (r > other.r) : (r<other.r);
	}
};

void mo_s_algorithm(vector<Query> queries){
	vector<long long> answer(queries.size());
	sort(queries.begin(), queries.end());
	
	int cur_l = 0;
	int cur_r = -1;
	for(Query q: queries){
		while(cur_l > q.l){
		 	cur_l--;
			add(cur_l);
		}
		while(cur_r < q.r){
		 	cur_r++;
			add(cur_r);
		}
		while(cur_l < q.l){
		 	remov(cur_l);
			cur_l++;
		}
		while(cur_r > q.r){
		 	remov(cur_r);
			cur_r--;
		}
		answer[q.idx] = get_answer();
	}
	for(long long it: answer){
		cout << it << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, aux;
	cin >> n >> m >> k;
	block_size = ceil(sqrt(n));
	v.assign(n+1, 0);
	for(int i=1; i<=n; i++){
		cin >> aux;
	 	v[i] = v[i-1]^aux;
	}
	vector<Query> queries(m);
	for(int i=0; i<m; i++){
	 	cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].idx = i;
	}
	mo_s_algorithm(queries);
	return 0;
}