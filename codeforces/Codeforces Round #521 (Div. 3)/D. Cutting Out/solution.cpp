#include <bits/stdc++.h>
using namespace std;

struct node{
	int idx, value;
	node(){ idx = 0, value = 0;}
	bool operator <(node other) const
	{
	 	return value > other.value;
	}
}

int dp[2e5+5];

vector<node> v(2e5+5);

int solucion(int idx, int k){
	int mmax = 0;
	for(int i=1; i<v[idx]; i++){
		int aux = solution(idx+1, k-i);
		if(aux > mmax){
		 	mmax = aux;
		 	dp[idx] = i;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, aux;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> aux;
		v[aux].idx = aux;
		v[aux].value++;
	}
	memset(dp, -1,sizeof dp);
	sort(v.begin(), v.end());
	solution(
	return 0;
}                    