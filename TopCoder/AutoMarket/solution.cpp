#include <bits/stdc++.h>
using namespace std;

struct node{
        int first, second, third;
        node(){ first=0; second=0; third=0;} 	
};

bool operator <(node a, node b){
	if(a.first==b.first){
		if(a.second==b.second){
			return a.third<b.third;
		}else return a.second>b.second;
	}else return a.first<b.first;
}


class AutoMarket{
	public:
	int maxSet(vector<int> cost, vector<int> features, vector<int> fixTimes){
		int ans=0;
	 	vector<node> v(cost.size());
	 	for(int i=0; i<(int)cost.size(); i++){
	 		v[i].first=cost[i];
			v[i].second=features[i];
			v[i].third=fixTimes[i];
		}
			sort(v.begin(), v.end());
		vector<int> d(cost.size(), 1);
		for(int i=0; i<(int)v.size(); i++){
			for(int j=0; j<i; j++){
			 	if(v[j].first<v[i].first && v[j].second>v[i].second && v[j].third<v[i].third)
			 		d[i] = max(d[i], d[j]+1);
			}
		}
		for(int i=0; i<(int)d.size(); i++) ans=max(ans, d[i]);
		return ans;
	}

};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> cost = {1000, 1000, 1000, 1000, 2000};
	vector<int> features = {3,3,4,3,3};
	vector<int> fixTimes = {3,3,3,4,3};
	AutoMarket AM;
	cout << AM.maxSet(cost, features, fixTimes) << '\n';
 	return 0;
}