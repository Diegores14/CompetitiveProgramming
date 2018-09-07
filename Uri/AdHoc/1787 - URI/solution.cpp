#include <bits/stdc++.h>
using namespace std;

bool ispowtwo(int n){
	int ans=0;
	for(int i=0; i<32; i++)ans+=(n>>i)&1;
	return ans==1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n, n){
		int a, b, c;
		vector<pair<int,string>> v(3);
		v[0]=pair<int,string>(0, "Uilton");
		v[1]=pair<int,string>(0, "Rita");
		v[2]=pair<int,string>(0, "Ingred");
	 	while(n--){
	 	 	cin >> a >> b >> c;
	 	 	if(ispowtwo(a)){
	 	 	 	if(b<a && c<a)v[0].first+=2;
	 	 	 	else v[0].first++;
	 	 	}
	 	 	if(ispowtwo(b)){
	 	 	 	if(a<b && c<b)v[1].first+=2;
	 	 	 	else v[1].first++;
	 	 	}
	 	 	if(ispowtwo(c)){
	 	 	 	if(b<c && a<c)v[2].first+=2;
	 	 	 	else v[2].first++;
	 	 	}
	 	} 
	 	sort(v.begin(), v.end());
	 	if(v[1].first == v[2].first) cout << "URI\n";
	 	else cout << v[2].second << '\n';
	}
	return 0;
}