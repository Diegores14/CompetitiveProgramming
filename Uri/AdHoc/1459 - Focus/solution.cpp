#include <bits/stdc++.h>
using namespace std;

struct node{
	int first, second;
	node(){}	
};

bool operator <(node a, node b){
 	if(a.second != b.second) return a.second < b.second;
 	else return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; 
	while(cin >> n){
		vector<node> v(n);
	 	for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
	 	int a=0, ans=0;
	 	sort(v.begin(), v.end());
		for(int i=0; i<n; i++) if(v[i].first>a){ans++; a=v[i].second;}
		cout << ans << '\n';
	}
	return 0;
}