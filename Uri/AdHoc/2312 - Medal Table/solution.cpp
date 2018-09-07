#include <bits/stdc++.h>
using namespace std;

struct node{
  	string s;
  	int a, b, c;
  	node(){a=0; b=0; c=0;}
};

bool operator <(node a, node b){
        if(a.a != b.a) return a.a < b.a;
        else{
         	if(a.b!=b.b) return a.b < b.b;
         	else{
         	 	if(a.c!=b.c) return a.c < b.c;
         	 	else{
         	 	 	return a.s > b.s;
         	 	}
         	}
        }
 	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	vector<node> v(n);
	for(int i=0; i<n; i++) cin >> v[i].s >> v[i].a >> v[i].b >> v[i].c;
	sort(v.begin(), v.end());
	for(int i=n-1; i>=0; i--) cout << v[i].s << ' ' << v[i].a << ' ' <<v[i].b << ' ' << v[i].c << '\n'
	;
	return 0;
}